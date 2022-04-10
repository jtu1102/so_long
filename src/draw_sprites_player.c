/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:58:14 by soahn             #+#    #+#             */
/*   Updated: 2022/04/10 12:56:33 by soahn            ###   ########.fr       */
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
	if (game->move_stat == LEFT || game->move_stat == RIGHT)
		col_pos_idx++;
	else
		row_pos_idx++;
	//벽에 부딪히는지, 한 칸 전부 이동했는지 확인해서 한번에 한 칸만 이동
	if (map[row_pos_idx][col_pos_idx] != '1' ||
		(!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE)))
	{
		game->player.x = game->player.x + game->offset[X];
		game->player.y = game->player.y + game->offset[Y];
	}
}

void	move_check_collec(t_game *game)
{
	char	**map;
	int		row_pos_idx;
	int		col_pos_idx;

	map = game->map.map;
	row_pos_idx = (game->player.y + game->offset[Y]) / TILE_SIZE;
	col_pos_idx = (game->player.x + game->offset[X]) / TILE_SIZE;
	if (!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE) &&
		map[row_pos_idx][col_pos_idx] == 'C')
	{
		//todo: collectable 먹는거 구현 - collective 삭제
		put_img(game, game->tile.background_ptr, row_pos_idx, col_pos_idx);
	}
}

void	move_check_exit(t_game *game)
{
	char	**map;
	int		row_pos_idx;
	int		col_pos_idx;

	map = game->map.map;
	row_pos_idx = (game->player.y + game->offset[Y]) / TILE_SIZE;
	col_pos_idx = (game->player.x + game->offset[X]) / TILE_SIZE;
	if (!((game->player.x + game->offset[X]) % TILE_SIZE) &&
		!((game->player.y + game->offset[Y]) % TILE_SIZE) &&
		map[row_pos_idx][col_pos_idx] == 'E')
	{
		//todo: collect 다 먹었는지 확인하기 (리스트 비었는지!)
		ft_putstr_fd("Win!", STDOUT_FILENO);
		exit_game(game);
	}
}

void	draw_sprites_player(t_game *game)
{
//moving 벽 확인해서 x, y 세팅하고, collectable 먹었는지, exit 들어가는지 확인해서 적절히 !
	move_check_wall(game);
	// check_collec(game);
	move_check_exit(game);
	game->move_log += STEP;
	put_img(game, game->player.sprites->ptr, game->player.x, game->player.y);
	game->player.sprites = game->player.sprites->next;
}