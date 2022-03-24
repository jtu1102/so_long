/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:47:21 by soahn             #+#    #+#             */
/*   Updated: 2022/03/24 21:26:37 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == W_KEY || keycode == UP_KEY)
		go_up(game, )
	return (0);
}
