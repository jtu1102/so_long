/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:04 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 05:37:17 by soahn            ###   ########.fr       */
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

typedef struct s_sprites
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
}		t_tile;

typedef struct s_player
{
	int	x;
	int	y;

	t_sprites	*initial;
	t_sprites	*sprites;

	t_sprites	*move_initial[4];
	t_sprites	*move_sprites[4];
}		t_player;

typedef struct s_collec
{
	void	*ptr;
}	t_collec;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			move_stat;
	int			offset;
	int			step;
	int			fps; // 500 번 마다 loop을 한번씩 건너뛴다. (왜?)
	t_map		map;
	t_tile		tile;
	t_player	player;
	t_collec	collec;
	int			flag[2];
}	t_game;

/* init_game.c */
void	init_game(t_game *game);

/* exit_game.c */
int	exit_game(t_game *game);

/* init_img.c */
void	init_img(t_game *game);

/* exit_msg.c */
void	exit_msg(char *msg);

/* mlx_img_helper.c */
void	*wrap_xpm_to_img(t_game *game, char *str);
void	put_img(t_game *game, void *img_ptr, int x, int y);

/* handle_key_press.c */
int	key_hook(int keycode, t_game *game);

/* loop_hook.c */
int	loop_hook(t_game *game);

/* exit_game.c */
int	exit_game(t_game *game);

/* draw.c */
void	draw_tiles(t_game *game);
void	draw_exit(t_game *game);

/* read_map.c */
void	read_map(t_game *game, char *path);

/* read_map_helper.c */
int	is_right_components(char c);
void	chk_walled(t_map maps);

#endif
