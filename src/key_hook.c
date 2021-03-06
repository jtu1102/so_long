/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:47:21 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 08:39:10 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	_print_step(int step)
{
	ft_putstr_fd("STEP: ", STDOUT_FILENO);
	ft_putnbr_fd(step, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	_sub_set_offset(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		game->move_stat = LEFT;
		game->offset[X] = -1 * STEP;
		game->offset[Y] = 0;
		game->player.stage_stop = game->player.stop_left;
		game->player.stage_sprites = game->player.sprites_left;
	}
	else if (keycode == KEY_D)
	{
		game->move_stat = RIGHT;
		game->offset[X] = 1 * STEP;
		game->offset[Y] = 0;
		game->player.stage_stop = game->player.stop_right;
		game->player.stage_sprites = game->player.sprites_right;
	}
}

static void	_set_offset(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->move_stat = UP;
		game->offset[X] = 0;
		game->offset[Y] = -1 * STEP;
		game->player.stage_stop = game->player.stop_up;
		game->player.stage_sprites = game->player.sprites_up;
	}
	else if (keycode == KEY_S)
	{
		game->move_stat = DOWN;
		game->offset[X] = 0;
		game->offset[Y] = 1 * STEP;
		game->player.stage_stop = game->player.stop_down;
		game->player.stage_sprites = game->player.sprites_down;
	}
	else if (keycode == KEY_D || keycode == KEY_A)
		_sub_set_offset(keycode, game);
}

int	key_hook(int keycode, t_game *game)
{
	if (game->move_stat != STOP)
		return (1);
	_print_step(++game->step);
	if (keycode == KEY_ESC)
		exit_game(game);
	_set_offset(keycode, game);
	return (1);
}
