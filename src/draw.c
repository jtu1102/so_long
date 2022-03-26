/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:16:59 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 04:22:08 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_tiles(t_game *game)
{
	int		i;
	int		j;
	t_map	map;

	map = game->map;
	i = -1;
	while (++i < map.rows)
	{
		j = -1;
		while (++j < map.cols)
		{
			if (map.map[i][j] == '1')
				put_img(game, game->tile.wall_ptr, i * TILE_SIZE, j * TILE_SIZE);
			else
				put_img(game, game->tile.background_ptr, i * TILE_SIZE, j * TILE_SIZE);
		}
	}
}

void	draw_exit(t_game *game)
{
	int		i;
	int		j;
	t_map	map;

	map = game->map;
	i = -1;
	while (++i < map.rows)
	{
		j = -1;
		while (++j < map.cols)
		{
			if (map.map[i][j] == 'E' && game->flag[EXIT_OPEN])
				put_img(game, game->tile.exit_ptr, i * TILE_SIZE, j * TILE_SIZE);
			else if (map.map[i][j] == 'E' && !game->flag[EXIT_OPEN])
				put_img(game, game->tile.closed_ptr, i * TILE_SIZE, j * TILE_SIZE);
		}
	}
}