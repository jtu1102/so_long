/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:47:21 by soahn             #+#    #+#             */
/*   Updated: 2022/04/10 14:16:11 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	_print_step(int step)
{
	ft_putstr_fd("STEP: ", STDOUT_FILENO);
	ft_putnbr_fd(step, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	_set_offset(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->move_stat = UP;
		game->offset[X] = 0;
		game->offset[Y] = -1 * STEP;
		game->player.initial = game->player.move_initial[UP];
		game->player.sprites = game->player.move_sprites[UP];
	}
	else if (keycode == KEY_S)
	{
		game->move_stat = DOWN;
		game->offset[X] = 0;
		game->offset[Y] = 1 * STEP;
		game->player.initial = game->player.move_initial[DOWN];
		game->player.sprites = game->player.move_sprites[DOWN];
	}
	else if (keycode == KEY_A)
	{
		game->move_stat = LEFT;
		game->offset[X] = -1 * STEP;
		game->offset[Y] = 0;
		game->player.initial = game->player.move_initial[LEFT];
		game->player.sprites = game->player.move_sprites[LEFT];
	}
	else if (keycode == KEY_D)
	{
		game->move_stat = RIGHT;
		game->offset[X] = 1 * STEP;
		game->offset[Y] = 0;
		game->player.initial = game->player.move_initial[RIGHT];
		game->player.sprites = game->player.move_sprites[RIGHT];
	}
}

int	key_hook(int keycode, t_game *game)
{
	_print_step(++game->step);
	if (keycode == KEY_ESC)
		exit_game(game);
	_set_offset(keycode, game);
	return (1);
}
