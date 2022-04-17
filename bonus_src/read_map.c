/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:30:30 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 20:01:30 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_msg("File open fail\n");
	return (fd);
}

void	map_save(t_game *game, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open_file(path);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((int)ft_strlen(line) != game->map.cols)
			exit_msg("Map is not rectangular.\n");
		j = -1;
		while (++j < game->map.cols)
		{
			if (!is_right_components(game, line[j]))
				exit_msg("Invalid component has found in the map.\n");
			game->map.map[i][j] = line[j];
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void	map_malloc(t_game *game, int fd)
{
	char	c;
	int		i;

	game->map.rows = 0;
	game->map.cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			game->map.rows++;
		else if (!game->map.rows)
			game->map.cols++;
	}
	game->map.map = (char **)malloc(sizeof(char *) * game->map.rows);
	if (game->map.map < 0)
		exit_msg("Memory not allocated\n");
	i = -1;
	while (++i < game->map.rows)
	{
		game->map.map[i] = (char *)malloc(sizeof(char) * game->map.cols);
		if (game->map.map[i] < 0)
			exit_msg("Memory not allocated\n");
	}
}

void	chk_extension(char *path)
{
	char	**p;
	int		i;

	i = 0;
	p = ft_split(path, '.');
	while (p[i + 1])
		++i;
	if (ft_strncmp(p[i], "ber", 3) != 0)
		exit_msg("Wrong extension of the map file.\n");
	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

void	read_map(t_game *game, char *path)
{
	int	fd;

	chk_extension(path);
	fd = open_file(path);
	map_malloc(game, fd);
	close(fd);
	map_save(game, path);
	chk_walled(game->map);
	chk_composition(game);
}
