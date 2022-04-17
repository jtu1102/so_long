/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:53:28 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 19:14:54 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_right_components(t_game *game, char c)
{
	if (c == 'P')
		game->cnt_comp[P]++;
	if (c == 'C')
		game->cnt_comp[C]++;
	if (c == 'E')
		game->cnt_comp[E]++;
	if (c == '0')
		game->cnt_comp[BG]++;
	if (c == '1')
		game->cnt_comp[WALL]++;
	if (c == 'P' || c == 'C' || c == 'E' || c == '0' || c == '1')
		return (TRUE);
	return (FALSE);
}

void	chk_walled(t_map maps)
{
	int	i;

	i = -1;
	while (++i < maps.rows)
	{
		if (maps.map[i][0] != '1' || maps.map[i][maps.cols - 1] != '1')
			exit_msg("Map is not walled.\n");
	}
	i = -1;
	while (++i < maps.cols)
	{
		if (maps.map[0][i] != '1' || maps.map[maps.rows - 1][i] != '1')
			exit_msg("Map is not walled.\n");
	}
}

void	chk_composition(t_game *game)
{
	if (game->cnt_comp[P] != 0)
		exit_msg("map should have one player position\n");
	if (game->cnt_comp[E] == 0)
		exit_msg("map should have at least one exit\n");
	if (game->cnt_comp[C] == 0)
		exit_msg("map should have at least one collectable\n");
}
