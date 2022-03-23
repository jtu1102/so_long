/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:10:32 by soahn             #+#    #+#             */
/*   Updated: 2022/03/23 20:51:06 by soahn            ###   ########.fr       */
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
	mlx_hook(game.mlx_ptr, KEY_PRESS, NO_MASK, &key_hook, &game); //Mac OS X 상에서 Mask 값은 사용되지 않는다.
	mlx_hook(game.win_ptr, KEY_EXIT, NO_MASK, &exit_game, &game);// key exit (17) 명령 --> 공부 필요. esc는 위에서 처리됨. 
	mlx_loop_hook(game.mlx_ptr, &loop_hook, &game); // hook이 없을 때의 동작 명령
	mlx_loop(game.mlx_ptr); // loop_hook 도 쓰고 loop도 써야 하는 이유가 모지? 
	return (0);
} 