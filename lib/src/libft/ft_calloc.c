/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 03:06:12 by jisokang          #+#    #+#             */
/*   Updated: 2022/04/18 20:38:38 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	new = malloc(count * size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, (count * size));
	return (new);
}
