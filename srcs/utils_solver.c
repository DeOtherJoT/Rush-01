/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:48:01 by jthor             #+#    #+#             */
/*   Updated: 2023/09/25 12:48:03 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush2.h"

int	get_pos_max(int *answer, int edge, int place, int flag)
{
	int	i;

	i = -1;
	if (flag == 1)
	{
		while (++i < edge)
		{
			if (answer[(i * edge) + (place % edge)] == edge)
				return (i);
		}
	}
	else
	{
		while (++i < edge)
		{
			if (answer[(edge * (place / edge)) + i] == edge)
				return (i);
		}
	}
	return (-1);
}

void	set_cons_data(t_cons *dat, int edge)
{
	dat->ctr1 = -1;
	dat->ctr2 = edge;
	dat->visible_1 = 1;
	dat->visible_2 = 1;
	dat->max1 = 0;
	dat->max2 = 0;
}
