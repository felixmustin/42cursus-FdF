/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:25:05 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/06 12:25:06 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	ft_create_image(t_data *data)
{
	data->mlx_img = mlx_new_image(data->mlx_ptr, 1200, 800);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	ft_reload_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_create_image (data);
	ft_process_point(data);
}
