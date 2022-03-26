/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:46:09 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 05:08:21 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define TRUE	1
# define FALSE	0

/* for game->flag */
# define BONUS	0
# define EXIT_OPEN 1

# define P 0
# define E 1
# define C 2
# define R 3 // bonus part (enemy)

# define EXIT_ERROR 1
# define TILE_SIZE 64 // todo: tile size check

/* for images */
# define ASSET_PATH "./asset/"

/* move status */
# define STOP 0
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

/* for mlx_hook */
# define KEY_PRESS 2
# define KEY_EXIT 17
# define NO_MASK 0
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

#endif