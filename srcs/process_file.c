/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:24:31 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/06 15:06:48 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

int	ft_process_file(t_data *data)
{
	data->map = ft_map_data(data->filen);
	if (data->map.x == 0 || data->map.y == 0)
		return (0);
	data->grid = ft_create_point_grid(data);
	if (!data->grid)
	{
		ft_putstr_fd("Error in the map", 1);
		return (0);
	}
	return (1);
}

void	ft_process_point(t_data *data)
{
	if (data->hook->exit == 1)
	{
		ft_tab_free(data->grid, data->map.y);
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		free(data->mlx_ptr);
		exit(0);
	}
	data->color = ((data->hook->red << 16) | (data->hook->green << 8)
			| data->hook->blue);
	if (data->hook->proj == 1)
		ft_transform_points(data);
	else if (data->hook->proj == 2)
		ft_transform_points_par(data);
	else
		ft_transform_points_up(data);
	data->mlx_img_cpy = data->mlx_img;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img_cpy, 0, 0);
	ft_put_menu(data);
}
