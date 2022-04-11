/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:55:52 by soahn             #+#    #+#             */
/*   Updated: 2022/04/12 00:59:21 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lst_add(t_position **head, int x, int y)
{
	t_position	*node;
	t_position	*now;

	node = (t_position *)malloc(sizeof(t_position));
	if (!node)
		exit_msg("no available memory\n");
	node->x = x;
	node->y = y;
	node->next = NULL;
	if (!*head)
	{
		*head = node;
		return ;
	}
	now = *head;
	while(now->next)
		now = now->next;
	now->next = node;
}

void	lst_delete(t_position **head, int xpos, int ypos)
{
	t_position	*now;
	t_position	*tmp;

	if ((*head)->x == xpos * TILE_SIZE && (*head)->y == ypos * TILE_SIZE)
	{
		*head = NULL;
		free(*head);
		return ;
	}
	now = *head;
	while (now->next)
	{
		if (now->next->x == xpos * TILE_SIZE && \
		now->next->y == ypos * TILE_SIZE)
		{
			tmp = now->next;
			now->next = now->next->next;
			tmp = NULL;
			free(tmp);
		}
		now = now->next;
	}
}