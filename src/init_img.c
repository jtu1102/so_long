/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:11:24 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 15:35:17 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	_init_tile(t_game *game)
{
	game->tile.background_ptr = wrap_xpm_to_img(game, "tile_bg.xpm");
	game->tile.wall_ptr = wrap_xpm_to_img(game, "tile_wall.xpm");
	game->tile.exit_ptr = wrap_xpm_to_img(game, "exit.xpm"); //todo: exit 이미지 너무 이상해 ㅋㅋㅋ바꿔.. 팻말이 제일 무난할듯..?
	game->tile.closed_ptr = wrap_xpm_to_img(game, "closed.xpm"); //todo: 이것도 이상해ㅠㅠㅋㅋㅋ하..
	//game->tile. = wrap_xpm_to_img(game, ".xpm");
}

static void	_init_player(t_game *game)
{
	game->player.move_initial[UP] = wrap_xpm_to_img(game, "player_up0.xpm");
	game->imgs.player[UP][1].ptr = wrap_xpm_to_img(game, "player_up1.xpm");
	game->imgs.player[UP][2].ptr = wrap_xpm_to_img(game, "player_up2.xpm");
	game->imgs.player[DOWN][0].ptr = wrap_xpm_to_img(game, "player_down0.xpm");
	game->imgs.player[DOWN][1].ptr = wrap_xpm_to_img(game, "player_down1.xpm");
	game->imgs.player[DOWN][2].ptr = wrap_xpm_to_img(game, "player_down2.xpm");
	game->imgs.player[LEFT][0].ptr = wrap_xpm_to_img(game, "player_left0.xpm");
	game->imgs.player[LEFT][1].ptr = wrap_xpm_to_img(game, "player_left1.xpm");
	game->imgs.player[LEFT][2].ptr = wrap_xpm_to_img(game, "player_left2.xpm");
	game->imgs.player[RIGHT][0].ptr = wrap_xpm_to_img(game, "player_right0.xpm");
	game->imgs.player[RIGHT][1].ptr = wrap_xpm_to_img(game, "player_right1.xpm");
	game->imgs.player[RIGHT][2].ptr = wrap_xpm_to_img(game, "player_right2.xpm");
}

static void	_init_other(t_game *game)
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
	_init_other(game);
}
