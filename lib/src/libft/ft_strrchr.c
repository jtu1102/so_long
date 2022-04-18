/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 04:10:22 by jisokang          #+#    #+#             */
/*   Updated: 2022/04/18 20:38:58 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == find)
			return ((char *)s + i);
		i--;
	}
	if (s[0] == find)
		return ((char *)s);
	return (0);
}
