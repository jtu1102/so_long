/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:10:32 by soahn             #+#    #+#             */
/*   Updated: 2022/04/13 20:31:59 by soahn            ###   ########.fr       */
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
	mlx_hook(game.win_ptr, KEY_EXIT, NO_MASK, &exit_game, &game);// key exit (17) 명령 --> red exit button activate
	mlx_key_hook(game.win_ptr, &key_hook, &game); //Mac OS X 상에서 Mask 값은 사용되지 않는다. -> 문제없음
	mlx_loop_hook(game.mlx_ptr, &loop_hook, &game); // hook이 없을 때의 동작 명령 -> 여기 확실히 문제 있음!
	mlx_loop(game.mlx_ptr); // loop_hook 도 쓰고 loop도 써야 하는 이유가 모지?
	return (0);
}
