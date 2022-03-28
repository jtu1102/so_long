/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:30 by soahn             #+#    #+#             */
/*   Updated: 2022/03/28 21:49:49 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//temporal version for compile
void	move_player(t_game *game)
{
	// if (game->move_stat == UP)
	// {
	// 	game->player.move_initial[UP].ptr;
	// }
	//printf("%d", game->player.x);
	++game->fps;
	--game->fps;
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
