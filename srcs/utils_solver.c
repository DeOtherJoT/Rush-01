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