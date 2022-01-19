/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:22:37 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/27 15:24:31 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

void	my_mlx_pixel_put(t_data *data, int xx, int yy, int color)
{
	char	*offset;

	if (color == 0)
		color = data->color;
	if (xx >= 0 && xx < 1200 && yy >= 0 && yy < 800)
	{
		offset = data->addr + (yy * (data->line_length)
				+ xx * (data->bits_per_pixel / 8));
		*(unsigned int *) offset = color;
	}
}

void	ft_hook_init(t_data *data, t_hook *hook)
{
	data->hook = hook;
	data->hook->exit = 0;
	data->hook->mult = 1;
	data->hook->ver = 0;
	data->hook->hor = 0;
	data->hook->red = 255;
	data->hook->green = 255;
	data->hook->blue = 255;
	data->hook->zoom = 1;
	data->hook->proj = 1;
}

int	ft_data_init(t_data *data, char *str)
{
	int	n;

	data->filen = NULL;
	n = ft_strlen(str) - 1;
	if (str[n--] == 'f')
	{
		if (str[n--] == 'd')
		{
			if (str[n] == 'f')
				data->filen = str;
		}
	}
	if (data->filen == NULL)
	{
		ft_putstr_fd("Error on filename", 1);
		return (0);
	}
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1200, 800, "FdF");
	if (!data->mlx_win)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	struct s_data	data;
	struct s_hook	hook;

	if (argc == 2)
	{
		if (!ft_data_init(&data, argv[1]))
			return (0);
		ft_hook_init(&data, &hook);
		ft_create_image (&data);
		if (!ft_process_file(&data))
		{
			mlx_destroy_image(data.mlx_ptr, data.mlx_img);
			mlx_destroy_window(data.mlx_ptr, data.mlx_win);
			free(data.mlx_ptr);
			return (0);
		}
		ft_process_point(&data);
		mlx_mouse_hook(data.mlx_win, ft_mouse_hook, &data);
		mlx_key_hook(data.mlx_win, ft_key_hook, &data);
		mlx_loop(data.mlx_ptr);
		ft_tab_free(data.grid, data.map.y);
	}
	else
		ft_putstr_fd("2 arguments needed", 1);
}
