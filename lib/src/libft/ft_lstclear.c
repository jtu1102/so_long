/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:51:01 by jisokang          #+#    #+#             */
/*   Updated: 2022/04/18 20:38:52 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next_lst;

	curr = *lst;
	while (curr != NULL)
	{
		next_lst = curr->next;
		ft_lstdelone(curr, del);
		curr = next_lst;
	}
	*lst = NULL;
}
