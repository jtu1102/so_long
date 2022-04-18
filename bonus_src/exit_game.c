/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:53:22 by soahn             #+#    #+#             */
/*   Updated: 2022/04/18 20:23:37 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

void	check_enemy(t_game *game)
{
	char	**map;
	int		row_pos_idx;
	int		col_pos_idx;

	map = game->map.map;
	row_pos_idx = (game->player.y + game->offset[Y]) / TILE_SIZE;
	col_pos_idx = (game->player.x + game->offset[X]) / TILE_SIZE;
	if (map[row_pos_idx][col_pos_idx] == 'N' &&
		!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE))
	{
		ft_putstr_fd("Lose!\n", STDOUT_FILENO);
		exit_game(game);
	}
}

void	check_exit(t_game *game)
{
	char	**map;
	int		row_pos_idx;
	int		col_pos_idx;

	map = game->map.map;
	row_pos_idx = (game->player.y + game->offset[Y]) / TILE_SIZE;
	col_pos_idx = (game->player.x + game->offset[X]) / TILE_SIZE;
	if (map[row_pos_idx][col_pos_idx] == 'E' &&
		!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE))
	{
		if (game->flag[EXIT_OPEN])
		{
			ft_putstr_fd("Win!\n", STDOUT_FILENO);
			exit_game(game);
		}
	}
}
