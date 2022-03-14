/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:43:04 by soahn             #+#    #+#             */
/*   Updated: 2022/03/14 22:45:14 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h> //왜?

# include "./config.h"
# include "../mlx/mlx.h"
# include "../lib/include/libft.h" //내
# include "../lib/include/ft_printf.h" //코드로
# include "../lib/include/get_next_line.h" //바꾸기!

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map;
	int		component[4]; //count the number of each components (player, exit, collectible item, enemy)
}	t_map;

typedef struct s_game
{
	void	*mlx;
	t_map	maps;

}	t_game;

# define TRUE	1
# define FALSE	0

#endif
