/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:10:32 by soahn             #+#    #+#             */
/*   Updated: 2022/03/14 21:30:09 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_msg("Usage: ./so_long {MAP_FILE.ber}\n");
	read_map(&game, argv[1]);
	init_game(&game);
	return (0);
} 