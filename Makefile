# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 15:13:27 by soahn             #+#    #+#              #
#    Updated: 2022/04/17 18:42:44 by soahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC		= gcc
CFLAGS 	= -Wall -Werror -Wextra
AR 		= ar rcs
RM 		= rm -f

INCS_DIR		= ./include/
SRCS_DIR		= ./src/
SRCS_DIR_BONUS 	= ./bonus_src/
LIB_DIR			= ./lib/
MLX_DIR			= ./mlx/
LIB_NAME		= ./lib/ftlib.a
MLX_NAME		= ./mlx/libmlx.a

INCS		= -I include
MLXFLAGS	= -lmlx -framework OpenGL -framework Appkit

SRC			= main.c draw_sprites.c draw.c exit_game.c exit_msg.c init_game.c init_img.c key_hook.c \
			loop_hook.c lst_helper.c mlx_img_helper.c read_map_helper.c read_map.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
SRCS_BONUS	= $(addprefix $(SRCS_DIR_BONUS), $(SRC))
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCS_DIR) -L $(LIB_DIR) -lft -L $(MLX_DIR) $(MLXFLAGS)

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -I $(INCS_DIR) -L $(LIB_DIR) -lft -L $(MLX_DIR) $(MLXFLAGS)

re_bonus : fclean bonus

PHONY	: all clean fclean re bonus re_bonus
