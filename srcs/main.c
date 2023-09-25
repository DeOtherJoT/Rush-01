#include "../includes/rush2.h"

/**
 * @brief	Prints the answer board in the t_data struct
*/
void	print_board(t_data *data)
{
	int	i;
	int	total;

	i = 0;
	total = data->edge * data->edge;
	while (i < total)
	{
		ft_putnbr(data->answer[i]);
		if ((i + 1) % data->edge == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

/**
 * @brief	Driver function. Program flow is as follows:
 * 			  1. Check if the number of arguments is correct.
 * 			  2. Initialise the t_Data struct which will contain the clue
 * 				 array and answer board, as well as the size of the board.
 *			  3. Start solver using backtracking algorithm.
 *			  4. If a solution is found, print it. Else, return error message.
 *			  5. Free malloc'd memory.
*/

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_error("Usage: ./rush-01 <clue string>", 1));
	data = parse_input(argv[1]);
	if (!data)
	{
		ft_error("Invalid input format", 2);
		return (2);
	}
	if (solver(data, 0) == FALSE)
	{
		ft_free_data(data);
		return (ft_error("No soutions found", 3));
	}
	else
		print_board(data);
	ft_free_data(data);
	return (0);
}