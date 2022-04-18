/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:18:34 by jisokang          #+#    #+#             */
/*   Updated: 2022/04/18 20:38:51 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (lst == NULL)
		return (NULL);
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}
