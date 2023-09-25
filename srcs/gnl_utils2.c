/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:24:39 by jthor             #+#    #+#             */
/*   Updated: 2023/09/25 13:24:40 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush2.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	if (dst == src)
		return (dst);
	if (dest > srce)
	{
		while (len--)
			dest[len] = srce[len];
		return (dst);
	}
	while (i < len)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}
