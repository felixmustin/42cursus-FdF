/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:56:13 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/13 15:10:31 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

int	ft_get_color(char *val)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (val[i] == ',')
		{
			i++;
			return (ft_atoi_base(val + i, "0123456789abcdef"));
		}
		i++;
	}
	return (0);
}

struct s_point	*ft_create_point_line(char **points, t_data *data)
{
	static int		index;
	struct s_point	*line;
	int				i;

	line = malloc (sizeof(struct s_point) * data->map.x);
	if (!line)
		return (0);
	i = 0;
	while (i < data->map.x)
	{
		line[i].x = (i * (600 / data->map.x));
		line[i].y = (index * (600 / data->map.x));
		if (!points[i])
		{
			free(line);
			return (0);
		}
		line[i].z = ft_atoi(points[i]);
		line[i].color = ft_get_color(points[i]);
		i++;
	}
	index++;
	return (line);
}

int	ft_create_point_grid_2(t_data *data, int fd, t_point **point_grid)
{
	char			**points;
	char			*line;
	int				i;

	i = -1;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		points = ft_split(line, ' ');
		if (!points)
			return (0);
		free(line);
		point_grid[++i] = ft_create_point_line(points, data);
		ft_tab_free_char(points);
		if (!point_grid[i])
		{
			ft_tab_free(point_grid, i);
			return (0);
		}
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

t_point	**ft_create_point_grid(t_data *data)
{
	struct s_point	**point_grid;
	int				fd;

	point_grid = malloc(sizeof(struct s_point *) * data->map.y);
	if (!point_grid)
		return(0);
	fd = open(data->filen, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!ft_create_point_grid_2(data, fd, point_grid))
		return (0);
	if (close(fd) == -1)
		return (0);
	return (point_grid);
}
