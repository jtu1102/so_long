/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:11:24 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 18:45:43 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	_init_tile(t_game *game)
{
	game->tile.background_ptr = wrap_xpm_to_img(game, "tile_bg.xpm");
	game->tile.wall_ptr = wrap_xpm_to_img(game, "tile_wall.xpm");
	game->tile.exit_ptr = wrap_xpm_to_img(game, "exit.xpm");
	game->tile.closed_ptr = wrap_xpm_to_img(game, "closed.xpm");
}

void	make_sprites_list(t_game *game, t_sprites **sprites, char *root_file)
{
	t_sprites	*now;
	char		*file;
	char		*file_xpm;
	int			i;
	int			n;

	*sprites = (t_sprites *)malloc(sizeof(t_sprites));
	now = *sprites;
	i = -1;
	while (++i < 3)
	{
		n = '0' + i;
		file = ft_strjoin(root_file, (char *)&n);
		file_xpm = ft_strjoin(file, ".xpm");
		now->ptr = wrap_xpm_to_img(game, file_xpm);
		free(file);
		free(file_xpm);
		if (i < 2)
		{
			now->next = (t_sprites *)malloc(sizeof(t_sprites));
			now = now->next;
		}
	}
	now->next = *sprites;
}

static void	_init_player(t_game *game)
{
	make_sprites_list(game, &game->player.sprites_up, "player_up");
	make_sprites_list(game, &game->player.sprites_down, "player_down");
	make_sprites_list(game, &game->player.sprites_left, "player_left");
	make_sprites_list(game, &game->player.sprites_right, "player_right");
	game->player.stop_up = game->player.sprites_up;
	game->player.stop_down = game->player.sprites_down;
	game->player.stop_left = game->player.sprites_left;
	game->player.stop_right = game->player.sprites_right;
	game->player.stage_stop = game->player.sprites_down;
	game->player.stage_sprites = game->player.sprites_down;
}

static void	_init_collect(t_game *game)
{
	t_sprites	*now;
	char		*file;
	char		*file_xpm;
	int			i;
	int			n;

	game->collec.sprites = (t_sprites *)malloc(sizeof(t_sprites));
	now = game->collec.sprites;
	i = -1;
	while (++i < 8)
	{
		n = '0' + i;
		file = ft_strjoin("heart", (char *)&n);
		file_xpm = ft_strjoin(file, ".xpm");
		now->ptr = wrap_xpm_to_img(game, file_xpm);
		free(file);
		free(file_xpm);
		if (i < 7)
		{
			now->next = (t_sprites *)malloc(sizeof(t_sprites));
			now = now->next;
		}
	}
	now->next = game->collec.sprites;
}

void	init_img(t_game *game)
{
	_init_tile(game);
	_init_player(game);
	_init_collect(game);
}
