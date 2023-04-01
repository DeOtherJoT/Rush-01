#ifndef RUSH2_H
# define RUSH2_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

typedef struct	s_data
{
	int	*answer;
	int	*clues;
	int	edge;
}	t_data;

typedef struct	s_cons
{
	int	ctr1;
	int	ctr2;
	int	visible_1;
	int	visible_2;
	int max1;
	int	max2;
	int pos_max;
}	t_cons;

// ft_split.c
char	**ft_split(char *str);

// input.c
t_data	*parse_input(char *clue_str);

// main.c
int		ft_error(char *str, int ret);

// solver.c
int		solver(t_data *data, int place);

// utils_solver.c
int		get_pos_max(int *answer, int edge, int place, int flag);
void	set_cons_data(t_cons *dat, int edge);

// utils.c
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_sqrt(int nb);
void	ft_free_data(t_data *data);

// utils2.c
int		ft_error(char *str, int ret);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_free_split(char **arr);

#endif