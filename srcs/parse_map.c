/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:23:56 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/13 15:10:55 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

int	ft_count_x(char *buf)
{
	int		j;
	size_t	i;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && i < ft_strlen(buf))
	{
		if (buf[i] == ' ')
		{
			j++;
			i++;
			while (buf[i] == ' ')
				i++;
		}
		else
		{
			while (buf[i] != ' ' && buf[i] != '\n' && i < ft_strlen(buf))
				i++;
		}
	}
	if (buf[i - 1] != ' ')
		j++;
	if (buf[0] == ' ')
		j--;
	return (j);
}

t_map	error(void)
{
	t_map	map;

	ft_putstr_fd("Error on file", 1);
	map.x = 0;
	map.x = 0;
	return (map);
}

int	protect(char **buf, char *file)
{
	int	n;

	if (!*buf || *buf[0] == '\n' || *buf[0] == '\0')
	{
		free(*buf);
		return (0);
	}
	n = ft_strlen(file);
	n--;
	if (file[n] == 'f')
	{
		n--;
		if (file[n] == 'd')
		{
			n--;
			if (file[n] == 'f')
				return (1);
		}
	}
	free(*buf);
	return (0);
}

struct s_map	ft_map_data(char *file)
{
	struct s_map		map;
	int					fd;
	int					y;
	char				*line;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error());
	line = get_next_line(fd);
	if (protect(&line, file) == 0)
		return (error());
	while (line)
	{
		y += 1;
		if (y == 1)
			map.x = ft_count_x(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map.y = y;
	if (close(fd) == -1)
		ft_putchar_fd('E', 1);
	return (map);
}
