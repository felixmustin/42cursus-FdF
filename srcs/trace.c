/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:37:05 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/06 14:18:11 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	horizontal_vertical(t_data *data, t_point start, t_point end, int dir)
{
	if (dir == 1)
	{
		while (++start.xx != end.xx)
			my_mlx_pixel_put(data, start.xx, start.yy, start.color);
	}
	else if (dir == 2)
	{
		while (--start.xx != end.xx)
			my_mlx_pixel_put(data, start.xx, start.yy, start.color);
	}
	else if (dir == 3)
	{
		while (++start.yy != end.yy)
			my_mlx_pixel_put(data, start.xx, start.yy, start.color);
	}
	else if (dir == 4)
	{
		while (--start.yy != end.yy)
			my_mlx_pixel_put(data, start.xx, start.yy, start.color);
	}
}

void	ft_trace_seg_2(t_point start, t_point end, t_data *data)
{
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	if (dy != 0)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				first_octant(data, start, end);
			else
				second_octant(data, start, end);
		}
		else if (dy < 0)
		{
			if (dx >= -dy)
				eighth_octant(data, start, end);
			else
				seventh_octant(data, start, end);
		}
	}
	else if (dy == 0)
		horizontal_vertical(data, start, end, 1);
}

void	ft_trace_seg_3(t_point start, t_point end, t_data *data)
{
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	if (dy != 0)
	{
		if (dy > 0)
		{
			if (-dx >= dy)
				fourth_octant(data, start, end);
			else
				third_octant(data, start, end);
		}
		else if (dy < 0)
		{
			if (dx <= dy)
				fifth_octant(data, start, end);
			else
				sixth_octant(data, start, end);
		}
	}
	else if (dy == 0)
		horizontal_vertical(data, start, end, 2);
}

void	ft_trace_seg(t_point start, t_point end, t_data *data)
{
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	if (dx != 0)
	{
		if (dx > 0)
			ft_trace_seg_2(start, end, data);
		else if (dx < 0)
			ft_trace_seg_3(start, end, data);
	}
	else if (dx == 0)
	{
		if (dy != 0)
		{
			if (dy > 0)
				horizontal_vertical(data, start, end, 3);
			else
				horizontal_vertical(data, start, end, 4);
		}
	}
}
