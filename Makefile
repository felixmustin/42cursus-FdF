# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmustin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:27:24 by fmustin           #+#    #+#              #
#    Updated: 2021/12/13 13:00:15 by fmustin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c \
	srcs/create_grid.c \
	srcs/free.c \
	srcs/ft_atoi_base.c \
	srcs/hook.c \
	srcs/menu.c \
	srcs/parse_map.c \
	srcs/process_file.c \
	srcs/process_image.c \
	srcs/trace.c \
	srcs/trace_1-4.c \
	srcs/trace_5-8.c \
	srcs/transform_points.c \
	get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c \

#UNCOMMENT THIS FOR MACOS
INCLUDES = main.h

#UNCOMMENT THIS FOR LINUX
#INCLUDES = main_linux.h

%.o:srcs%.c
	$(CC) $(CCFLAG) $(MLX_INC) $(FT_INC) -I $(INCLUDES) -o $@ -c $<

OBJS = ${SRC:.c=.o}

CC = gcc $(CCFLAG)

CCFLAG = -Wall -Wextra -Werror -fsanitize=address -g

#UNCOMMENT THIS FOR MACOS
MLX		= ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx_macos
MLX_LNK	= -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

#UNCOMMENT THIS FOR LINUX
#MLX		= ./minilibx_linux/
#MLX_LIB	= $(addprefix $(MLX),mlx.a)
#MLX_INC	= -I ./minilibx_linux
#MLX_LNK	= -L ./minilibx_linux -l mlx -lbsd -lX11 -lXext

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

RM = rm -f

all:		$(FT_LIB) $(MLX_LIB) ${NAME}

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

${NAME}:	${OBJS}
			$(CC) $(OBJS) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
			${RM} ${OBJS}
			make -C $(FT) fclean
			make -C $(MLX) clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
