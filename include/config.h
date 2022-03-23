/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:46:09 by soahn             #+#    #+#             */
/*   Updated: 2022/03/22 23:33:06 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define TRUE	1
# define FALSE	0

# define BONUS	0

# define P 0
# define E 1
# define C 2
# define R 3 // bonus part (enemy)

# define EXIT_ERROR 1
# define TILE_SIZE 64 // todo: tile size check

/* for images */
# define ASSET_PATH "./asset/"

# define BACKGROUND 0
# define WALL 1
# define EXIT_CLOSED 2
# define EXIT_OPEN 3
# define COUNT_BOX 4

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

/* for mlx_hook */
# define KEY_PRESS 2
# define KEY_EXIT 17
# define NO_MASK 0
#endif