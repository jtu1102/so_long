/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:30 by soahn             #+#    #+#             */
/*   Updated: 2022/04/18 20:18:29 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_player(t_game *game)
{
	draw_tiles(game);
	draw_sprites_collec(game);
	draw_exit(game);
	draw_sprites_player(game);
	if (!(game->move_log % TILE_SIZE))
	{
		draw_tiles(game);
		draw_sprites_collec(game);
		draw_exit(game);
		game->player.stage_sprites = game->player.stage_stop;
		put_img(game, game->player.stage_stop->ptr,
			game->player.x, game->player.y);
		game->move_stat = STOP;
		game->move_log = 0;
	}
}

int	loop_hook(t_game *game)
{
	if (game->move_stat != STOP)
		move_player(game);
	else
		draw_sprites_collec(game);
	return (1);
}
