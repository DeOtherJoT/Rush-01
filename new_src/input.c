#include "../includes/rush2.h"

static int	get_arr_len(char **arr)
{
	int	ret;

	ret = 0;
	while (arr[ret])
		ret++;
	return (ret);
}

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

static int	*init_answer(int edge)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * (edge * edge));
	i = 0;
	while (i < (edge * edge))
		ret[i] = 0;
	return (ret);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

t_data	*parse_input(char *clue_str)
{
	t_data	*ret;
	int		*clue_arr;
	char	**ret_split;

	// process input
	ret_split = ft_split(clue_str);
	clue_arr = process_clue(ret_split);

	// assign input
	ret = malloc(sizeof(t_data));
	ret->clues = clue_arr;
	printf("%d\n", get_arr_len(ret_split));
	ret->edge = ft_sqrt(get_arr_len(ret_split));
	ret->answer = init_answer(ret->edge);

	// if invalid input, free and return
	ft_free_split(ret_split);
	if (ret->edge == 0 || ret->edge < 4)
	{
		printf("%d\n", ret->edge);
		ft_error("Invalid input format", -1);
		ft_free_data(ret);
		return (NULL);
	}
	return (ret);
}