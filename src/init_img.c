/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:11:24 by soahn             #+#    #+#             */
/*   Updated: 2022/04/08 00:39:57 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void _init_tile(t_game *game)
{
	game->tile.background_ptr = wrap_xpm_to_img(game, "tile_bg.xpm");
	game->tile.wall_ptr = wrap_xpm_to_img(game, "tile_wall.xpm");
	game->tile.exit_ptr = wrap_xpm_to_img(game, "exit.xpm");	 // todo: exit 이미지 너무 이상해 ㅋㅋㅋ바꿔.. 팻말이 제일 무난할듯..?
	game->tile.closed_ptr = wrap_xpm_to_img(game, "closed.xpm"); // todo: 이것도 이상해ㅠㅠㅋㅋㅋ하..
}

static void _init_player(t_game *game)
{
	make_sprites_list(game, &game->player.move_initial[UP], "player_up");
	make_sprites_list(game, &game->player.move_initial[DOWN], "player_down");
	make_sprites_list(game, &game->player.move_initial[LEFT], "player_left");
	make_sprites_list(game, &game->player.move_initial[RIGHT], "player_right");
	game->player.move_initial[UP] = game->player.move_sprites[UP];
	game->player.move_initial[DOWN] = game->player.move_sprites[DOWN];
	game->player.move_initial[LEFT] = game->player.move_sprites[LEFT];
	game->player.move_initial[RIGHT] = game->player.move_sprites[RIGHT];
	game->player.initial = game->player.move_sprites[DOWN]; // 정지 해 있을 때 초기모습 (?)
	game->player.sprites = game->player.move_sprites[DOWN];
}

static void _init_collect(t_game *game)
{
	game->collec.ptr = NULL;
	// if (game->flag[BONUS])
	// 	game->imgs.enemy.ptr = wrap_xpm_to_img(game, ".xpm");
	// game->imgs.collec.ptr = wrap_xpm_to_img(game, "heart.xpm");
}

void init_img(t_game *game)
{
	_init_tile(game);
	_init_player(game);
	_init_collect(game);
}
