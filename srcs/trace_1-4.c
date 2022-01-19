/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_1-4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:18:22 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/06 14:37:22 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	first_octant(t_data *data, t_point start, t_point end)
{
	int	e;
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	e = dx;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		my_mlx_pixel_put(data, start.xx, start.yy, start.color);
		if (++start.xx == end.xx)
			return ;
		e -= dy;
		if (e < 0)
		{
			start.yy += 1;
			e += dx;
		}
	}
}

void	second_octant(t_data *data, t_point start, t_point end)
{
	int	e;
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	e = dy;
	dy *= 2;
	dx *= 2;
	while (1)
	{
		my_mlx_pixel_put(data, start.xx, start.yy, start.color);
		if (++start.yy == end.yy)
			return ;
		e -= dx;
		if (e < 0)
		{
			start.xx += 1;
			e += dy;
		}
	}
}

void	third_octant(t_data *data, t_point start, t_point end)
{
	int	e;
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	e = dy;
	dy *= 2;
	dx *= 2;
	while (1)
	{
		my_mlx_pixel_put(data, start.xx, start.yy, start.color);
		if (++start.yy == end.yy)
			return ;
		e += dx;
		if (e <= 0)
		{
			start.xx -= 1;
			e += dy;
		}
	}
}

void	fourth_octant(t_data *data, t_point start, t_point end)
{
	int	e;
	int	dx;
	int	dy;

	dx = end.xx - start.xx;
	dy = end.yy - start.yy;
	e = dx;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		my_mlx_pixel_put(data, start.xx, start.yy, start.color);
		if ((--start.xx) == end.xx)
			return ;
		e += dy;
		if (e >= 0)
		{
			start.yy += 1;
			e += dx;
		}
	}
}
