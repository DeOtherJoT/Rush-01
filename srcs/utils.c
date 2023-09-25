/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:48:10 by jthor             #+#    #+#             */
/*   Updated: 2023/09/25 12:48:11 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush2.h"

/**
 * @brief	Basic strlen function
 * 
 * @return	The length of the string passed as the parameter
*/

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

/**
 * @brief	Basic atoi function
 * 
 * @return	The int represented by the string parameter
*/

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	neg = 1;
	while (*str && *str == ' ')
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	res = 0;
	while (*str)
	{
		if (*str == '\n')
			break ;
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

/**
 * @brief	Frees the malloc'd t_data struct
*/

void	ft_free_data(t_data *data)
{
	free(data->answer);
	free(data->clues);
	free(data);
}
