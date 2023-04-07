#include "../includes/rush2.h"

/**
 * @brief	Takes an array of strings and returns the size of the array.
*/

static int	get_arr_len(char **arr)
{
	int	ret;

	ret = 0;
	while (arr[ret])
		ret++;
	return (ret);
}

/**
 * @brief	Initialises an int array based on the array of numbers as
 * 			strings.
 * 
 * @returns	An integer array, representing the clues given as the program's
 * 			input.
*/

static int	*process_clue(char **arr)
{
	int	*ret;
	int	arr_len;
	int	i;

	arr_len = get_arr_len(arr);
	ret = malloc(sizeof(int) * arr_len);
	i = -1;
	while (++i < arr_len)
		ret[i] = ft_atoi(arr[i]);
	return (ret);
}

/**
 * @brief	Initialises an int array of length (edge * edge).
 * 			This can be interpreted as a 2D integer array, with clever
 * 			maths using the operations / and % with the value of edge.
 * 
 * @returns An integer array, representing the answer board.
*/

static int	*init_answer(int edge)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * (edge * edge));
	i = -1;
	while (++i < (edge * edge))
		ret[i] = 0;
	return (ret);
}

/**
 * @brief	Checks the int clue array for invalid numbers, either:
 * 			  A) Lesser than 1.
 * 			  B) More than the edge of the board.
 *
 * @returns	Either 0 or 1, expanded from FALSE or TRUE respectively.
*/

static int	check_input(t_data *data)
{
	int	i;
	int	total;

	if (data->edge < 4)
		return (FALSE);
	i = -1;
	total = data->edge * 4;
	while (++i < total)
	{
		if (data->clues[i] > data->edge || data->clues[i] < 1)
			return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief	Parses the clue input string into an int array, and if no
 * 			problems are found, initialise the answer board and find
 * 			out the edge of the board (how many ints along one edge)
 * 
 * @returns	Returns a pointer to a malloc'd t_data struct.
*/

t_data	*parse_input(char *clue_str)
{
	t_data	*ret;
	int		*clue_arr;
	char	**ret_split;

	ret_split = ft_split(clue_str);
	if (get_arr_len(ret_split) % 4 != 0)
	{
		ft_free_split(ret_split);
		return (NULL);
	}
	clue_arr = process_clue(ret_split);
	ret = malloc(sizeof(t_data));
	ret->clues = clue_arr;
	ret->edge = (get_arr_len(ret_split)) / 4;
	ret->answer = init_answer(ret->edge);
	ft_free_split(ret_split);
	if (check_input(ret) == FALSE)
	{
		ft_free_data(ret);
		return (NULL);
	}
	return (ret);
}