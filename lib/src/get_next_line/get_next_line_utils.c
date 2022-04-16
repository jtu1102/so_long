/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:46:50 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 07:33:25 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen_gnl(src);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_size;

	if (size == 0)
		return (ft_strlen_gnl(src));
	dest_size = ft_strlen_gnl(dest);
	if (size < dest_size)
		return (ft_strlen_gnl(src) + size);
	i = dest_size;
	j = 0;
	while (src[j] && i < (size - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (ft_strlen_gnl(src) + dest_size);
}

char	*ft_str_join(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!(s1) || !(s2))
	{
		if (!(s1))
			return (ft_str_dup(s2));
		return (ft_str_dup(s1));
	}
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy_gnl(res, s1, s1_len + 1);
	free(s1);
	ft_strlcpy_gnl(res + s1_len, s2, s2_len + 1);
	return (res);
}

char	*ft_str_dup(char *src)
{
	char	*dest;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen_gnl(src);
	dest = (char *)malloc(sizeof(char) * src_len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
