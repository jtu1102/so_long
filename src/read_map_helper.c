/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:53:28 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 05:37:05 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int	is_right_components(char c)
{
	if (c == 'P')
		return TRUE;
	if (c == 'E')
		return TRUE;
	if (c == 'C')
		return TRUE;
	if (c == '0')
		return TRUE;
	if (c == '1')
		return TRUE;
	return FALSE;
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

// void	map_components(t_game *game)
// {
// 	game
// 	return;
// }