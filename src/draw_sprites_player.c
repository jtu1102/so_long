/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:58:14 by soahn             #+#    #+#             */
/*   Updated: 2022/04/08 01:35:55 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_sprites_player(t_game *game)
{
//moving 벽 확인해서 x, y 세팅하고, collectable 먹었는지, exit 들어가는지 확인해서 적절히 !
	move_check_wall(game);
	// check_collec(game);
	move_check_exit(game);
	game->move_log += STEP;
	put_img(game, game->player.sprites->ptr, game->player.x, game->player.y);
	game->player.sprites = game->player.sprites->next;
}