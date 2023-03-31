#include "../includes/rush2.h"

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
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_error("Invalid input", 1));
	data = parse_input(argv[1]);
	if (!data)
		return (2);
	// if (solver(data, 0) == FALSE)
	// 	return (ft_error("No soutions found", 3));
	// else
	print_board(data);
	ft_free_data(data);
	return (0);
}