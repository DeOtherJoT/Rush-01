/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:19:38 by jthor             #+#    #+#             */
/*   Updated: 2023/09/25 13:19:39 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush2.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_c;
	const char	*src_c;

	i = 0;
	dst_c = (char *)dst;
	src_c = (const char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, s1, len);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (0);
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (0);
	ft_memmove(ptr, s1, s1_len);
	ft_memmove((ptr + s1_len), s2, s2_len);
	ptr[s1_len + s2_len] = '\0';
	return (ptr);
}
