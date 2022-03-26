# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 15:13:27 by soahn             #+#    #+#              #
#    Updated: 2022/03/26 06:46:25 by soahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC		= gcc
CFLAGS 	= -Wall -Werror -Wextra -g
AR 		= ar rcs
RM 		= rm -f

INCS_DIR	= ./include/
SRCS_DIR	= ./src/
LIB_DIR		= ./lib/
MLX_DIR		= ./mlx/
# LIB_NAME	= ./lib/ftlib.a
# MLX_NAME	= ./mlx/libmlx.a

INCS		= -I include
MLXFLAGS	= -lmlx -framework OpenGL -framework Appkit

SRC			= main.c draw.c exit_game.c exit_msg.c init_game.c init_img.c key_hook.c \
			loop_hook.c mlx_img_helper.c read_map_helper.c read_map.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(SRCS:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
#make -C $(LIB_DIR)
#make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCS_DIR) -L $(LIB_DIR) -lft -L $(MLX_DIR) $(MLXFLAGS)

all : $(NAME)

clean :
#make -C $(LIB_DIR) clean
#make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
#make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : fclean all

PHONY	: all clean fclean re