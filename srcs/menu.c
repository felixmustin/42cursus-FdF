/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:23:34 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/07 14:25:03 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	ft_put_menu(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 20, 0xFFFFFF, "Commands");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 30, 0xFFFFFF, "--------");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 50, 0xFFFFFF,
		"Zoom + : Left click");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 75, 0xFFFFFF,
		"Zoom - : Right click");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 100, 0xFFFFFF,
		"Height + : M");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 125, 0xFFFFFF,
		"Height - : L");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 150, 0xFFFFFF, "Color :");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 100, 150, 0xFFFFFF,
		"Red : T/Y");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 100, 175, 0xFFFFFF,
		"Green : G/H");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 100, 200, 0xFFFFFF,
		"Blue : V/B");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 225, 0xFFFFFF,
		"Change projection : P");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 25, 250, 0xFFFFFF,
		"Move : Arrows");
}
