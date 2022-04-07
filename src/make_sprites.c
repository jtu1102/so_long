/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:08:22 by soahn             #+#    #+#             */
/*   Updated: 2022/04/08 00:31:15 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	make_sprites_list(t_game *game, t_sprites **sprites, char *root_file)
{
	t_sprites	*now;
	char		*file;
	char		*file_xpm;
	int			i;
	int			n;

	*sprites = (t_sprites *)malloc(sizeof(t_sprites));
	now = *sprites;
	i = -1;
	while (++i < 3)
	{
		n = '0' + i;
		file = ft_strjoin(root_file, (char *)&n);
		file_xpm = ft_strjoin(file, ".xpm");
		now->ptr = wrap_xpm_to_img(game, file_xpm);
		free(file);
		free(file_xpm);
		if (i < 2)
		{
			now->next = (t_sprites *)malloc(sizeof(t_sprites));
			now = now->next;
		}
	}
	now->next = *sprites; // circular linked list
}