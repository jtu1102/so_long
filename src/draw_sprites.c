/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:58:14 by soahn             #+#    #+#             */
/*   Updated: 2022/04/16 15:12:39 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_check_wall(t_game *game) //얘가! 문제야!
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
	//벽에 부딪히는지. ?? todo. 이해하거나 코드 빼기
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
		!((game->player.y + game->offset[Y]) % TILE_SIZE)) // collec 위로 올라가면서 먹게 구현
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
		!((game->player.y + game->offset[Y]) % TILE_SIZE)) // 움직임을 자연스럽게 하기 위한 조건들.. exit 위로 올라가면 그게 보이면서 종료되도록 함
	{
		//todo: collect 다 먹었는지 확인하기 (리스트 비었는지!)
		if (game->flag[EXIT_OPEN])
		{
			ft_putstr_fd("Win!\n", STDOUT_FILENO);
			exit_game(game);
		}
	}
}

void	draw_sprites_player(t_game *game)
{
//moving 벽 확인해서 x, y 세팅하고, collectable 먹었는지, exit 들어가는지 확인해서 적절히 !
	move_check_wall(game);
	eat_collectable(game);
	check_exit(game);
	game->move_log += STEP;
	put_img(game, game->player.stage_sprites->ptr, game->player.x, game->player.y);
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
