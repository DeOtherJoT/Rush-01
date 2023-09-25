/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:49:45 by jthor             #+#    #+#             */
/*   Updated: 2023/09/25 12:49:48 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush2.h"

int	*parse_ans(int fd, int edge)
{
	char	*line;
	char	**split;
	int		*ret;
	int		i;
	int		j;

	ret = ft_calloc(edge * edge, sizeof(int));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line);
		j = -1;
		while (++j < edge)
		{
			ret[i] = ft_atoi(split[j]);
			i++;
		}
		free(line);
		ft_free_split(split);
	}
	return (ret);
}

void	checker(t_data *data, int *ans_arr)
{
	int	total;
	int	i;
	int	ans;

	total = data->edge * data->edge;
	i = -1;
	while (++i < total)
	{
		ans = constraint_check(ans_arr, data->clues, data->edge, i);
		if (ans == FALSE)
		{
			write(STDERR_FILENO, "KO!\n", 4);
			return ;
		}
	}
	write(STDOUT_FILENO, "OK!\n", 4);
}

void	checker_clear(t_data *data, int ans_fd, int *ans_arr)
{
	free(ans_arr);
	ft_free_data(data);
	close(ans_fd);
}

int	main(int argc, char **argv)
{
	int		ans_fd;
	int		*taken_ans;
	t_data	*data;

	if (argc != 3)
		return(ft_error("Usage: ./checker <clues> <answer file>", 4));
	ans_fd = open(argv[2], O_RDONLY);
	if (ans_fd == -1)
		return(ft_error("Bad answer file", 5));
	data = parse_input(argv[1]);
	if (!data)
		return(ft_error("Invalid input format", 6));
	taken_ans = parse_ans(ans_fd, data->edge);
	checker(data, taken_ans);
	checker_clear(data, ans_fd, taken_ans);
	return (0);
}
