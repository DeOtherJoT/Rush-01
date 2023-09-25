#include "../includes/rush2.h"

/**
 * @brief	Checks the answer board for duplicate values.
 * 
 * @return	0 or 1, expanded from FALSE or TRUE respectively.
*/

int	check_double(int *ans, int edge, int place)
{
	int	curr_val;
	int	i;

	curr_val = ans[place];
	i = -1;
	while (++i < (place % edge))
	{
		if (ans[(edge * (place / edge)) + i] == curr_val)
			return (FALSE);
	}
	i = -1;
	while (++i < (place / edge))
	{
		if (ans[(i * edge) + (place % edge)] == curr_val)
			return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief	Check the validity of the value at a certain place using the clues
 * 			given at the top and bottom edge.
 * 
 * @return	0 or 1, expanded from FALSE or TRUE respectively.
*/

int	check_top_bottom(int *ans, int *clue, int edge, int place)
{
	t_cons	dat;

	set_cons_data(&dat, edge);
	dat.pos_max = get_pos_max(ans, edge, place, 1);
	while (++dat.ctr1 < dat.pos_max)
	{
		if (ans[(dat.ctr1 * edge) + (place % edge)] > dat.max1)
		{
			dat.max1 = ans[(dat.ctr1 * edge) + (place % edge)];
			dat.visible_1++;
		}
	}
	while (--dat.ctr2 > dat.pos_max)
	{
		if (ans[(dat.ctr2 * edge) + (place % edge)] > dat.max2)
		{
			dat.max2 = ans[(dat.ctr2 * edge) + (place % edge)];
			dat.visible_2++;
		}
	}
	if (dat.visible_1 != clue[place % edge] ||
		dat.visible_2 != clue[edge + (place % edge)])
		return (FALSE);
	return (TRUE);
}

/**
 * @brief	Check the validity of the value at a certain place using the clues
 * 			given at the left and right edge.
 * 
 * @return	0 or 1, expanded from FALSE or TRUE respectively.
*/

int	check_left_right(int *ans, int *clue, int edge, int place)
{
	t_cons	dat;

	set_cons_data(&dat, edge);
	dat.pos_max = get_pos_max(ans, edge, place, 2);
	while (++dat.ctr1 < dat.pos_max)
	{
		if (ans[(edge * (place / edge)) + dat.ctr1] > dat.max1)
		{
			dat.max1 = ans[(edge * (place / edge) + dat.ctr1)];
			dat.visible_1++;
		}
	}
	while (--dat.ctr2 > dat.pos_max)
	{
		if (ans[(edge * (place / edge)) + dat.ctr2] > dat.max2)
		{
			dat.max2 = ans[(edge * (place / edge)) + dat.ctr2];
			dat.visible_2++;
		}
	}
	if (dat.visible_1 != clue[(edge * 2) + (place / edge)] ||
		dat.visible_2 != clue[(edge * 3) + (place / edge)])
		return (FALSE);
	return (TRUE);
}

/**
 * @brief	Checks if the value at a certain place fits within the constraints
 * 			which are no repetitions and with respect to the edge clues.
 * 
 * @param ans	The answer baord, represented as an integer array.
 * @param clue	The input clues, represented as an integer array.
 * @param edge	The length of the answer board.
 * @param place	The current position of the inserted value.
 * @return int 
 */

int	constraint_check(int *ans, int *clue, int edge, int place)
{
	if (check_double(ans, edge, place) == FALSE)
		return (FALSE);
	if ((place / edge) == (edge - 1))
	{
		if (check_top_bottom(ans, clue, edge, place) == FALSE)
			return (FALSE);
	}
	if ((place % edge) == (edge - 1))
	{
		if (check_left_right(ans, clue, edge, place) == FALSE)
			return (FALSE);
	}
	return (TRUE);

}

int	solver(t_data *data, int place)
{
	int	value;

	/* Base Case, a solution is found. */
	if (place == (data->edge * data->edge))
		return (TRUE);
	value = 1;
	while (value <= data->edge)
	{
		data->answer[place] = value;
		if (constraint_check(data->answer, data->clues, data->edge, place))
		{
			/* General Case, place is incremented as recurse control */
			if (solver(data, place + 1) == TRUE)
				return (TRUE);
		}
		else
			data->answer[place] = 0;
		value++;
	}
	/* If no value is possible, a previous place has a wrong value.*/
	return (FALSE);
}