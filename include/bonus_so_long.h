/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:04 by soahn             #+#    #+#             */
/*   Updated: 2022/04/13 20:00:32 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h> //왜?

# include "./config.h"
# include "../mlx/mlx.h"
# include "../lib/include/libft.h" //내
# include "../lib/include/ft_printf.h" //코드로
# include "../lib/include/get_next_line.h" //바꾸기!

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map;
	int		component[4]; //count the number of each components (player, exit, collectible item, enemy)
}	t_map;

typedef struct s_sprites // just list
{
	void	*ptr;
	struct s_sprites	*next;
}	t_sprites;

typedef struct s_tile
{
	void	*background_ptr;
	void	*wall_ptr;
	void	*exit_ptr;
	void	*closed_ptr;
}	t_tile;

typedef struct s_player
{
	int	x;
	int	y;

	t_sprites	*initial; // 현재 움직이는 방향의 리스트 첫번째 포인터 올리기
	t_sprites	*sprites; // 현재 움직이는 방향의 리스트 포인터 올리기

	t_sprites	*initial_up;
	t_sprites	*initial_down;
	t_sprites	*initial_left;
	t_sprites	*initial_right;
	t_sprites	*sprites_up;
	t_sprites	*sprites_down;
	t_sprites	*sprites_left;
	t_sprites	*sprites_right;
}	t_player;

typedef struct s_position
{
	int					x;
	int					y;
	struct s_position	*next;
}	t_position;

typedef struct s_collec
{
	t_position	*head;
	t_sprites	*sprites;
}	t_collec;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			move_stat; // 눌린 키값을 판단하는 변수
	int			move_log; // 64마다 초기화 하는 변수, 움직임 멈추기 위해 필요
	int			offset[2]; // 상하좌우로 움직일 칸 개수 설정
	int			step; // 키 눌린 횟수
	int			fps; // 500 번 마다 loop을 한번씩 건너뛴다. (왜?)
	t_map		map;
	t_tile		tile;
	t_player	player;
	t_collec	collec;
	int			flag[2];
}	t_game;

/* draw_sprites.c */
void	draw_sprites_player(t_game *game);
void	draw_sprites_collec(t_game *game);

/* draw.c */
void	draw_tiles(t_game *game);
void	draw_exit(t_game *game);
void	draw_player(t_game *game);
void	draw_collec(t_game *game);

/* init_game.c */
void	init_game(t_game *game);

/* exit_game.c */
int	exit_game(t_game *game);

/* init_img.c */
void	init_img(t_game *game);

/* exit_msg.c */
void	exit_msg(char *msg);

/* key_hook.c */
int	key_hook(int keycode, t_game *game);

/* mlx_img_helper.c */
void	*wrap_xpm_to_img(t_game *game, char *str);
void	put_img(t_game *game, void *img_ptr, int x, int y);

/* handle_key_press.c */
int	key_hook(int keycode, t_game *game);

/* loop_hook.c */
int	loop_hook(t_game *game);

/* lst_helper.c */
void	lst_add(t_position **head, int x, int y);
void	lst_delete(t_position **head, int x, int y);

/* exit_game.c */
int	exit_game(t_game *game);

/* read_map.c */
void	read_map(t_game *game, char *path);

/* read_map_helper.c */
int	is_right_components(char c);
void	chk_walled(t_map maps);

#endif
