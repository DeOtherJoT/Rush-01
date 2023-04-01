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
	i = -1;
	while (++i < (edge * edge))
		ret[i] = 0;
	return (ret);
}

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
		if (data->clues[i] > data->edge)
			return (FALSE);
	}
	return (TRUE);
}

t_data	*parse_input(char *clue_str)
{
	t_data	*ret;
	int		*clue_arr;
	char	**ret_split;

	ret_split = ft_split(clue_str);
	clue_arr = process_clue(ret_split);
	if (get_arr_len(ret_split) % 4 != 0)
	{
		ft_free_split(ret_split);
		return (NULL);
	}
	ret = malloc(sizeof(t_data));
	ret->clues = clue_arr;
	ret->edge = (get_arr_len(ret_split)) / 4;
	ret->answer = init_answer(ret->edge);
	ft_free_split(ret_split);
	if (check_input(ret) == FALSE)
	{
		ft_error("Invalid input format", -1);
		ft_free_data(ret);
		return (NULL);
	}
	return (ret);
}