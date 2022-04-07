/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:16:59 by soahn             #+#    #+#             */
/*   Updated: 2022/04/08 00:44:08 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_tiles(t_game *game)
{
	int		x;
	int		y;
	t_map	map;

	map = game->map;
	y = -1;
	while (++y < map.rows)
	{
		x = -1;
		while (++x < map.cols)
		{
			put_img(game, game->tile.background_ptr, x * TILE_SIZE, y * TILE_SIZE); // i, x 좌표 reverse
			if (map.map[y][x] == '1')
				put_img(game, game->tile.wall_ptr, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

void	draw_exit(t_game *game)
{
	int		x;
	int		y;
	t_map	map;

	map = game->map;
	y = -1;
	while (++y < map.rows)
	{
		x = -1;
		while (++x < map.cols)
		{
			if (map.map[y][x] == 'E' && game->flag[EXIT_OPEN] == FALSE)
				put_img(game, game->tile.exit_ptr, x * TILE_SIZE, y * TILE_SIZE);
			else if (map.map[y][x] == 'E' && game->flag[EXIT_OPEN] == TRUE)
				put_img(game, game->tile.closed_ptr, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

void	draw_player(t_game *game)
{
	int		x;
	int		y;
	t_map	map;

	map = game->map;
	y = -1;
	while (++y < map.rows)
	{
		x = -1;
		while (++x < map.cols)
			if (map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				put_img(game, game->player.initial->ptr, x * TILE_SIZE, y * TILE_SIZE);
			}
	}
}
