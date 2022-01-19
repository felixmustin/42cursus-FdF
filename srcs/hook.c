/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:22:15 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/07 14:25:48 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__)
# include "../main.h"
#else
# include "../main_linux.h"
#endif

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == M_CLK_L)
		data->hook->zoom += 0.25;
	else if (button == M_CLK_R)
		data->hook->zoom -= 0.25;
	ft_reload_window(data);
	return (1);
}

void	ft_key_hook2(int keycode, t_data *data)
{
	if (keycode == K_G)
		data->hook->green += 10;
	else if (keycode == K_H)
		data->hook->green -= 10;
	else if (keycode == K_T)
		data->hook->red += 10;
	else if (keycode == K_Y)
		data->hook->red -= 10;
	else if (keycode == K_V)
		data->hook->blue += 10;
	else if (keycode == K_B)
		data->hook->blue -= 10;
	else if (keycode == K_ESC)
		data->hook->exit = 1;
	else if (keycode == K_P)
	{
		if (data->hook->proj == 1)
			data->hook->proj++;
		else if (data->hook->proj == 2)
			data->hook->proj++;
		else if (data->hook->proj == 3)
			data->hook->proj = 1;
	}	
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == K_AR_U)
		data->hook->ver += 10;
	else if (keycode == K_AR_D)
		data->hook->ver -= 10;
	else if (keycode == K_AR_L)
		data->hook->hor -= 10;
	else if (keycode == K_AR_R)
		data->hook->hor += 10;
	else if (keycode == K_M)
		data->hook->mult += 0.25;
	else if (keycode == K_L)
		data->hook->mult -= 0.25;
	else
		ft_key_hook2(keycode, data);
	ft_reload_window(data);
	return (1);
}
