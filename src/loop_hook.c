/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:30 by soahn             #+#    #+#             */
/*   Updated: 2022/04/10 12:20:52 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game)
{
	draw_tiles(game);
	draw_exit(game);
	draw_sprites_player(game);
}

int	loop_hook(t_game *game)
{
	if (++game->fps < 500)
	{
		if (game->move_stat != STOP)
			move_player(game);
		return (1);
	}
	game->fps = 0;
	return (1);
}
