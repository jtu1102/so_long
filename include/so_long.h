/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:04 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 19:11:34 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>

# include "./config.h"
# include "../mlx/mlx.h"
# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map;
}	t_map;

typedef struct s_sprites
{
	void				*ptr;
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
	int			x;
	int			y;

	t_sprites	*stage_stop;
	t_sprites	*stage_sprites;

	t_sprites	*stop_up;
	t_sprites	*stop_down;
	t_sprites	*stop_left;
	t_sprites	*stop_right;
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
	int			move_stat;
	int			move_log;
	int			offset[2];
	int			step;
	t_map		map;
	t_tile		tile;
	t_player	player;
	t_collec	collec;
	int			flag[2];
	int			cnt_comp[6];
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
int		exit_game(t_game *game);

/* init_img.c */
void	init_img(t_game *game);

/* exit_msg.c */
void	exit_msg(char *msg);

/* key_hook.c */
int		key_hook(int keycode, t_game *game);

/* mlx_img_helper.c */
void	*wrap_xpm_to_img(t_game *game, char *str);
void	put_img(t_game *game, void *img_ptr, int x, int y);

/* handle_key_press.c */
int		key_hook(int keycode, t_game *game);

/* loop_hook.c */
int		loop_hook(t_game *game);

/* lst_helper.c */
void	lst_add(t_position **head, int x, int y);
void	lst_delete(t_position **head, int x, int y);

/* exit_game.c */
int		exit_game(t_game *game);

/* read_map.c */
void	read_map(t_game *game, char *path);

/* read_map_helper.c */
int		is_right_components(t_game *game, char c);
void	chk_walled(t_map maps);
void	chk_composition(t_game *game);

#endif
