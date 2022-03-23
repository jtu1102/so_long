/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:09:05 by soahn             #+#    #+#             */
/*   Updated: 2022/03/20 00:29:36 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	init_flag(t_game *game)
{
	game->flag[BONUS] = FALSE;
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_msg("mlx init fail\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->maps.cols * \
	TILE_SIZE, game->maps.rows * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		exit_msg("mlx window init fail\n");
	init_img(game);
	init_flag(game);
}