/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:52:30 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 05:09:56 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//temporary for compile 
void	move_player(t_game *game)
{
	game->player.x = 0;
	return ;
}

int	loop_hook(t_game *game)
{
	if (++game->fps > 500)
	{
		if (game->move_stat != STOP)
			move_player(game);
		return (1);
	}
	game->fps = 0;
	return (1);
}