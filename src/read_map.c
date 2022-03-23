/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:30:30 by soahn             #+#    #+#             */
/*   Updated: 2022/03/17 19:54:27 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_save(t_game *game, char path)
{
// save line by line of the map + check if the map is walled 
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open_file(path);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != game->maps.cols)
			exit_msg("Map is not rectangular.\n");
		j = -1;
		while (++j < game->maps.cols)
		{
			if (!is_right_components(line[j]))
				exit_msg("Invalid component has found in the map.\n");
			game->maps.map[i][j] = line[j];
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

	game->maps.rows = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n') // number of \n == number of rows
			game->maps.rows++;
		else if (!game->maps.rows) // count colums with the first row
			game->maps.cols++;
	}
	game->maps.map = (char **)malloc(sizeof(char *) * game->maps.rows);
	if (game->maps.map < 0)
		exit_msg("Memory not allocated\n");
	i = -1;
	while (++i < game->maps.rows)
	{
		game->maps.map[i] = (char *)malloc(sizeof(char) * game->maps.cols);
		if (game->maps.map[i] < 0)
			exit_msg("Memory not allocated\n");
	}
}

int		open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_msg("File open fail\n");
	return (fd);
}

void	chk_extension(char *path)
{
	char	**p;
	char	*n;

	p = ft_split(path, '.');
	n = p[0];
	while (n + 1)
		++n;
	if (ft_strncmp(n, "ber", 3) != TRUE)
		exit_msg("Wrong extension of the map file.\n");
}

void	read_map(t_game *game, char *path)
{
	int	fd;

	chk_extension(path); // chk the extension of the map file (.ber)
	fd = open_file(path);
	map_malloc(game, fd); // memory allocation
	close(fd);
	map_save(game, path); // save line by line of the map + check if the map is walled 
	chk_walled(game->maps);
	// map_components(game); 아직 왜 세야 하는지 모르겠어서 패스.
}