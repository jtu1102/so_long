/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:11:24 by soahn             #+#    #+#             */
/*   Updated: 2022/03/28 20:55:24 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	_init_tile(t_game *game)
{
	game->tile.background_ptr = wrap_xpm_to_img(game, "tile_bg.xpm");
	game->tile.wall_ptr = wrap_xpm_to_img(game, "tile_wall.xpm");
	game->tile.exit_ptr = wrap_xpm_to_img(game, "exit.xpm"); //todo: exit 이미지 너무 이상해 ㅋㅋㅋ바꿔.. 팻말이 제일 무난할듯..?
	game->tile.closed_ptr = wrap_xpm_to_img(game, "closed.xpm"); //todo: 이것도 이상해ㅠㅠㅋㅋㅋ하..
}

static void	_init_player(t_game *game)
{
	game->player.move_initial[UP].ptr = wrap_xpm_to_img(game, "player_up0.xpm");
	game->player.move_initial[DOWN].ptr = wrap_xpm_to_img(game, "player_down0.xpm");
	game->player.move_initial[LEFT].ptr = wrap_xpm_to_img(game, "player_left0.xpm");
	game->player.move_initial[RIGHT].ptr = wrap_xpm_to_img(game, "player_right0.xpm");
}

static void	_init_collect(t_game *game)
{
	game->collec.ptr = NULL;
	// if (game->flag[BONUS])
	// 	game->imgs.enemy.ptr = wrap_xpm_to_img(game, ".xpm");
	// game->imgs.collec.ptr = wrap_xpm_to_img(game, "heart.xpm");
}

void	init_img(t_game *game)
{
	_init_tile(game);
	_init_player(game);
	_init_collect(game);
}
