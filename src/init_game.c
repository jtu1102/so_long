/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:09:05 by soahn             #+#    #+#             */
/*   Updated: 2022/04/07 23:35:08 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	init_flag(t_game *game)
{
	game->flag[BONUS] = FALSE;
	game->flag[EXIT_OPEN] = FALSE;
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_msg("mlx init fail\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.cols * \
	TILE_SIZE, game->map.rows * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		exit_msg("mlx window init fail\n");
	init_img(game);
	init_flag(game);
	draw_tiles(game);
	draw_player(game);
	//draw_collec(game);
	draw_exit(game);
}
