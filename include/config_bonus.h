/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:46:09 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 19:14:30 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# define TILE_SIZE 64

# define TRUE	1
# define FALSE	0

/* for game->flag */
# define BONUS	0
# define EXIT_OPEN 1

# define P 0
# define C 2
# define E 3
# define BG 4
# define WALL 5

# define EXIT_ERROR 1
# define TILE_SIZE 64

/* for images */
# define ASSET_PATH "./asset/"

/* move status, player img index */
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define STOP 4

/* offset */
# define X 0
# define Y 1

/* for mlx_hook */
# define KEY_EXIT 17
# define NO_MASK 0
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53

# define STEP 4

#endif
