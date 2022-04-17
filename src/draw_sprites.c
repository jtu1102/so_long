/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:58:14 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 08:38:48 by soahn            ###   ########.fr       */
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
	if (game->offset[X] > 0)
		col_pos_idx++;
	else if (game->offset[Y] > 0)
		row_pos_idx++;
	if (map[row_pos_idx][col_pos_idx] != '1' ||
		(!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE)))
	{
		game->player.x = game->player.x + game->offset[X];
		game->player.y = game->player.y + game->offset[Y];
	}
}

void	eat_collectable(t_game *game)
{
	char	**map;
	int		row_pos_idx;
	int		col_pos_idx;

	map = game->map.map;
	row_pos_idx = (game->player.y + game->offset[Y]) / TILE_SIZE;
	col_pos_idx = (game->player.x + game->offset[X]) / TILE_SIZE;
	if (map[row_pos_idx][col_pos_idx] == 'C' &&
	!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE))
	{
		lst_delete(&game->collec.head, col_pos_idx, row_pos_idx);
		if (!(game->collec.head))
			game->flag[EXIT_OPEN] = TRUE;
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

void	draw_sprites_player(t_game *game)
{
	move_check_wall(game);
	eat_collectable(game);
	check_exit(game);
	game->move_log += STEP;
	put_img(game, game->player.stage_sprites->ptr,
		game->player.x, game->player.y);
	game->player.stage_sprites = game->player.stage_sprites->next;
}

void	draw_sprites_collec(t_game *game)
{
	t_position	*now;

	now = game->collec.head;
	while (now)
	{
		put_img(game, game->collec.sprites->ptr, now->x, now->y);
		now = now->next;
	}
	game->collec.sprites = game->collec.sprites->next;
}
