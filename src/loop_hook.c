/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:30 by soahn             #+#    #+#             */
/*   Updated: 2022/04/13 20:43:34 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game)
{
	draw_tiles(game);
	draw_sprites_collec(game);
	draw_exit(game);
	draw_sprites_player(game); //***얘가 확실히..확실히 문제여
	if (!(game->move_log  % TILE_SIZE))
	{
		draw_tiles(game);
		draw_sprites_collec(game);
		draw_exit(game);
		game->player.sprites = game->player.initial;
		put_img(game, game->player.sprites->ptr, game->player.x, game->player.y);
		game->move_stat = STOP;
	}
}

int	loop_hook(t_game *game)
{
	if (++game->fps < 500)
	{
		if (game->move_stat != STOP)
			move_player(game);
		else
			draw_sprites_collec(game);
		return (1);
	}
	game->fps = 0;
	return (1);
}
