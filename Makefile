# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 18:33:46 by sesnowbi          #+#    #+#              #
#    Updated: 2021/04/14 20:07:14 by sesnowbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
LIBFT_D	= ./libft
LIBFT_A	= libft.a
#MLX_D	= ./minilibx_opengl
MLX_D	= ./minilibx_mms
#MLX_A	= libmlx.a
MLX_A	= libmlx.dylib
SRCS	= main.c GNL/get_next_line.c GNL/get_next_line_utils.c \
			initialize_and_free/ft_init_free_scene.c initialize_and_free/ft_conv_rgb_to_hex.c initialize_and_free/init_utils.c initialize_and_free/init_utils1.c \
			parse_check/ft_check_args.c parse_check/ft_error_kill.c parse_check/ft_check_parse_config.c parse_check/ft_check_parse_resol.c \
			parse_check/ft_check_parse_dir_spr.c parse_check/ft_dir_spr_utils.c parse_check/ft_check_parse_floor_ceil.c parse_check/parser_utils.c \
			parse_check/ft_check_begin_line.c parse_check/ft_check_map.c parse_check/ft_parse_map_check_walls.c parse_check/ft_fullfill_map.c parse_check/ft_check_walls.c \
			draw_cub/ft_draw_cub.c draw_cub/draw_utils.c draw_cub/hooks.c draw_cub/ft_ray_cast.c draw_cub/ft_draw_nswe.c draw_cub/tex_utils.c \
			draw_cub/sprite_utils.c draw_cub/ft_draw_sprites.c draw_cub/bar_dist_utils.c draw_cub/ft_screen_save.c draw_cub/move.c draw_cub/move_rotate.c
INC		= includes/cub3d.h
OBJS	= $(SRCS:.c=.o)

BONUS	= 
B_OBJS	= $(BONUS:.c=.o)

#-fsanitize=address
#CFLAGS	= -g -fsanitize=address
#FLAGS	= -g -L. -lft -lmlx -fsanitize=address
CC		= gcc
RM		= /bin/rm -f
CFLAGS	= -g -Wall -Werror -Wextra #-fsanitize=address
FLAGS	= -g -L. -lft -lmlx -Wall -Werror -Wextra #-fsanitize=address# -framework OpenGL -framework AppKit

.c.o:
	$(CC) $(CFLAGS) -c $< -include $(INC) -o $(<:.c=.o)

$(NAME):		$(OBJS)
					$(MAKE) bonus -C $(LIBFT_D)
					cp $(LIBFT_D)/$(LIBFT_A) .
					$(MAKE) -C $(MLX_D)
					mv $(MLX_D)/$(MLX_A) .
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:			$(INC) $(NAME)

clean:
				$(RM) $(OBJS) $(B_OBJS)
				$(MAKE) clean -C $(LIBFT_D)
				$(MAKE) clean -C $(MLX_D)

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(LIBFT_A)
					$(RM) $(MLX_A)
					$(MAKE) fclean -C $(LIBFT_D)
					$(MAKE) clean -C $(MLX_D)

re:				fclean all

bonus:			$(OBJS) $(B_OBJS)
					$(MAKE) bonus -C $(LIBFT_D)
					cp $(LIBFT_D)/$(LIBFT_A) .
					$(MAKE) -C $(MLX_D)
					mv $(MLX_D)/$(MLX_A) .
					$(CC) $(FLAGS) $(OBJS) $(B_OBJS) -o $(NAME)

.PHONY:			all clean fclean re bonus
