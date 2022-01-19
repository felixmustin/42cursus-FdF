/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_5-8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:10:30 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/07 14:17:39 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	fifth_octant(t_data *data, t_point start, t_point end)
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
		e -= dy;
		if (e >= 0)
		{
			start.yy -= 1;
			e += dx;
		}
	}
}

void	sixth_octant(t_data *data, t_point start, t_point end)
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
		if (--start.yy == end.yy)
			return ;
		e -= dx;
		if (e >= 0)
		{
			start.xx -= 1;
			e += dy;
		}
	}
}

void	seventh_octant(t_data *data, t_point start, t_point end)
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
		if ((--start.yy) == end.yy)
			return ;
		e += dx;
		if (e > 0)
		{
			start.xx += 1;
			e += dy;
		}
	}
}

void	eighth_octant(t_data *data, t_point start, t_point end)
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
		if ((++start.xx) == end.xx)
			return ;
		e += dy;
		if (e < 0)
		{
			start.yy -= 1;
			e += dx;
		}
	}
}
