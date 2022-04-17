/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:55:52 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 18:45:53 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	while (now->next)
		now = now->next;
	now->next = node;
}

void	_first_delete(t_position **head, t_position *tmp)
{
	*head = tmp->next;
	free(tmp);
	tmp = NULL;
	return ;
}

void	lst_delete(t_position **head, int xpos, int ypos)
{
	t_position	*now;
	t_position	*tmp;
	t_position	*prev;

	tmp = *head;
	if (tmp && (tmp->x == xpos * TILE_SIZE && tmp->y == ypos * TILE_SIZE))
		_first_delete(head, tmp);
	prev = *head;
	now = *head;
	while (now && now->next)
	{
		if (now->next->x == xpos * TILE_SIZE && \
		now->next->y == ypos * TILE_SIZE)
		{
			tmp = now->next;
			now->next = now->next->next;
			free(tmp);
			tmp = NULL;
		}
		now = now->next;
	}
}
