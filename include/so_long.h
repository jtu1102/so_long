/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:04 by soahn             #+#    #+#             */
/*   Updated: 2022/03/23 20:56:22 by soahn            ###   ########.fr       */
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

typedef struct s_img_config
{
	void	*ptr;
	int		*data;
	int		w;
	int		h;
}		t_img_config;

typedef struct s_img
{
	t_img_config	tile[5];
	t_img_config	player[4][3];
	t_img_config	collec;
	t_img_config	enemy;
}		t_img;

typedef struct s_game
{
	t_map	maps;
	void	*mlx_ptr;
	void	*win_ptr;
	int		flag[1];
	t_img	imgs;

}	t_game;

/* mlx_img_helper.c */
void	*wrap_xpm_to_img(t_game *game, char *str);

/* handle_key_press.c */
int	key_hook(int keycode, t_game *game);

/* loop_hook.c */
int	loop_hook(t_game *game);

/* exit_game.c */
int	exit_game(t_game *game);

#endif
