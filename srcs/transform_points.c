/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:25:14 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/07 14:18:31 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	ft_trace_2(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map.x)
	{
		i = 0;
		while (i + 1 < data->map.y)
		{
			ft_trace_seg(data->grid[i][j], data->grid[i + 1][j], data);
			i++;
		}
		j++;
	}
}

void	ft_trace(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j + 1 < data->map.x)
		{
			ft_trace_seg(data->grid[i][j], data->grid[i][j + 1], data);
			j++;
		}
		i++;
	}
	ft_trace_2(data);
}

void	ft_transform_points(t_data *data)
{
	double	a;
	int		i;
	int		j;

	a = 0.523599;
	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			data->grid[i][j].xx = 600 + data->hook->hor
				+ (data->grid[i][j].x - data->grid[i][j].y) * cos(a);
			data->grid[i][j].yy = 200 + data->hook->ver
				+ (data->grid[i][j].x + data->grid[i][j].y) * sin(a)
				- (data->hook->mult * data->grid[i][j].z);
			data->grid[i][j].xx *= data->hook->zoom;
			data->grid[i][j].yy *= data->hook->zoom;
			j++;
		}
		i++;
	}
	ft_trace(data);
}

void	ft_transform_points_par(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			data->grid[i][j].xx = 400 + data->hook->hor
				+ data->grid[i][j].x;
			data->grid[i][j].yy = 200 + data->hook->ver
				+ data->grid[i][j].y;
			data->grid[i][j].xx *= data->hook->zoom;
			data->grid[i][j].yy *= data->hook->zoom;
			j++;
		}
		i++;
	}
	ft_trace(data);
}

void	ft_transform_points_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (j < data->map.x)
		{
			data->grid[i][j].xx = 400 + data->hook->hor
				+ data->grid[i][j].x;
			data->grid[i][j].yy = 400 + data->hook->ver
				+ (data->hook->mult * -data->grid[i][j].z);
			data->grid[i][j].xx *= data->hook->zoom;
			data->grid[i][j].yy *= data->hook->zoom;
			j++;
		}
		i++;
	}
	ft_trace(data);
}
