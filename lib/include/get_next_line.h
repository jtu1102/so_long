/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:45:50 by soahn             #+#    #+#             */
/*   Updated: 2022/04/17 00:27:36 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen_gnl(const char *str);
size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size);
size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size);
char	*ft_str_join(char *s1, char *s2);
char	*ft_str_dup(char *src);

#endif
