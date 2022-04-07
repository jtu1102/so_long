/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:29:34 by soahn             #+#    #+#             */
/*   Updated: 2022/04/08 01:41:29 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_check_wall(t_game *game)
{
	char	**map;
	int		row_pos_idx;
	int		col_pos_idx;

	map = game->map.map;
	row_pos_idx = (game->player.y + game->offset[Y]) / TILE_SIZE;
	col_pos_idx = (game->player.x + game->offset[X]) / TILE_SIZE;
}

void	move_check_collec(t_game *game)
{//todo: collectable 먹는거 구현
	game->flag[0] = game->flag[0];
}

void	move_check_exit(t_game *game)
{
	
}