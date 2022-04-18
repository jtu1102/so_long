/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:16:59 by soahn             #+#    #+#             */
/*   Updated: 2022/04/18 20:10:21 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
			if (map.map[y][x] == '0' || map.map[y][x] == 'N'
				|| map.map[y][x] == 'P' || map.map[y][x] == 'C')
				put_img(game, game->tile.background_ptr,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (map.map[y][x] == '1')
				put_img(game, game->tile.wall_ptr,
					x * TILE_SIZE, y * TILE_SIZE);
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
			if (map.map[y][x] == 'E')
			{
				put_img(game, game->tile.background_ptr,
					x * TILE_SIZE, y * TILE_SIZE);
				if (game->flag[EXIT_OPEN] == FALSE)
					put_img(game, game->tile.closed_ptr,
						x * TILE_SIZE, y * TILE_SIZE);
				else if (game->flag[EXIT_OPEN] == TRUE)
					put_img(game, game->tile.exit_ptr,
						x * TILE_SIZE, y * TILE_SIZE);
			}
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
		{
			if (map.map[y][x] == 'P')
			{
				game->player.x = x * TILE_SIZE;
				game->player.y = y * TILE_SIZE;
				put_img(game, game->player.stage_stop->ptr,
					game->player.x, game->player.y);
			}
		}
	}
}

void	draw_collec(t_game *game)
{
	int			x;
	int			y;
	t_map		map;

	game->
	map = game->map;
	y = -1;
	while (++y < map.rows)
	{
		x = -1;
		while (++x < map.cols)
			if (map.map[y][x] == 'C')
				lst_add(&game->collec.head,
					x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	draw_enemy(t_game *game)
{
	int			x;
	int			y;
	t_map		map;

	map = game->map;
	y = -1;
	while (++y < map.rows)
	{
		x = -1;
		while (++x < map.cols)
			if (map.map[y][x] == 'N')
				lst_add(&game->enemy.head,
					x * TILE_SIZE, y * TILE_SIZE);
	}
}
