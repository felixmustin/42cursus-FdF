/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmustin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:42:12 by fmustin           #+#    #+#             */
/*   Updated: 2021/12/07 14:21:04 by fmustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line_bonus.h"  
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_hook
{
	double	mult;
	int		exit;
	int		ver;
	int		hor;
	int		red;
	int		green;
	int		blue;
	double	zoom;
	int		proj;
}	t_hook;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		xx;
	int		yy;
	int		color;
}	t_point;

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_data
{
	char	*filen;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*mlx_img_cpy;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	t_hook	*hook;
	t_point	**grid;
	t_map	map;
}	t_data;

//process_file
int		ft_process_file(t_data *data);
void	ft_process_point(t_data *data);

//process_image
void	ft_create_image(t_data *data);
void	ft_reload_window(t_data *data);

//free
t_point	**ft_tab_free(t_point **s, int i);
char	**ft_tab_free_char(char **s);

//hook
int		ft_mouse_hook(int button, int x, int y, t_data *data);
int		ft_key_hook(int keycode, t_data *data);

//create_grid
t_point	**ft_create_point_grid(t_data *data);
int		ft_create_point_grid_2(t_data *data, int fd, t_point **point_grid);

//parse_map
t_map	ft_map_data(char *file);

//trace
void	ft_trace_seg(t_point start, t_point end, t_data *data);

//transform points
void	ft_transform_points(t_data *data);
void	ft_transform_points_par(t_data *data);
void	ft_transform_points_up(t_data *data);

//trace_1-4
void	first_octant(t_data *data, t_point start, t_point end);
void	second_octant(t_data *data, t_point start, t_point end);
void	third_octant(t_data *data, t_point start, t_point end);
void	fourth_octant(t_data *data, t_point start, t_point end);
//trace_5-8
void	fifth_octant(t_data *data, t_point start, t_point end);
void	sixth_octant(t_data *data, t_point start, t_point end);
void	seventh_octant(t_data *data, t_point start, t_point end);
void	eighth_octant(t_data *data, t_point start, t_point end);

//main
void	my_mlx_pixel_put(t_data *data, int xx, int yy, int color);

long	ft_atoi_base(char *str, char *base_from);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

//menu
void	ft_put_menu(t_data *data);

// Keyboard LETTERS

# define K_B 11
# define K_G 5
# define K_H 4
# define K_L 37
# define K_M 41
# define K_P 35
# define K_T 17
# define K_V 9
# define K_Y 16

// Keyboard ARROWS

# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 125
# define K_AR_D 126

// Keyboard MISC

# define K_ESC 53

// Mouse

# define M_CLK_L 1
# define M_CLK_R 2

#endif
