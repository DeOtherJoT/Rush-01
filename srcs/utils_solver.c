#include "../includes/rush2.h"

/**
 * @brief	Depending on the flag parameter, locates the position of the
 * 			tallest skyscraper, either in the column or row.
 * 
 * @return	The position of the tallest skyscraper, imagined as a 0-indexed
 * 			array with respect to the current row or column.
*/

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

/**
 * @brief	Initialises the struct t_cons to be used in the constraint check
 * 			functions.
*/

void	set_cons_data(t_cons *dat, int edge)
{
	dat->ctr1 = -1;
	dat->ctr2 = edge;
	dat->visible_1 = 1;
	dat->visible_2 = 1;
	dat->max1 = 0;
	dat->max2 = 0;
}