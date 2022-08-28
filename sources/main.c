#include "../includes/rush.h"

void	display_solution(int puzzle[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(puzzle[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	check_split(char **arr)
{
	int	len;
	int	temp_val;

	len = 0;
	while (arr[len] != NULL)
	{
		temp_val = ft_atoi(arr[len]);
		if (temp_val < 1 || temp_val > 4)
			return (-1);
		len++;
	}
	if (len != 16)
		return (-1);
	return (1);
}

int	*clue_init(char *str)
{
	int		i;
	int		*ret;
	char	**temp_split;

	temp_split = ft_split(str, ' ');
	if (check_split(temp_split) == -1)
		return (NULL);
	ret = malloc(sizeof(int) * 16);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < 16)
		ret[i] = ft_atoi(temp_split[i]);
	ft_free_array(temp_split, 16);
	return (ret);
}

int	ft_put_error(int flag)
{
	if (flag == 0)
		ft_putstr("Error\n");
	else
		ft_putstr("No solution\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	puzzle[4][4];
	int	*clue;

	if (argc != 2)
		return (ft_put_error(0));
	clue = clue_init(argv[1]);
	if (clue == NULL)
	{
		ft_putstr("here\n");
		return (ft_put_error(0));
	}
	if (solution(puzzle, clue, 0) == 1)
		display_solution(puzzle);
	else
		ft_put_error(1);
	return (0);
}