#ifndef RUSH2_H
# define RUSH2_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

typedef struct s_data
{
	int	*answer;
	int	*clues;
	int	edge;
}	t_data;

// ft_split.c
char	**ft_split(char *str);

// input.c
t_data	*parse_input(char *clue_str);

// main.c
int		ft_error(char *str, int ret);

// utils.c
size_t	ft_strlen(char *str);
void	ft_free_arr(char **arr);
int		ft_atoi(char *str);
int		ft_sqrt(int nb);
void	ft_free_data(t_data *data);

// utils2.c
int		ft_error(char *str, int ret);
void	ft_putchar(char c);
void	ft_putnbr(int nb);


#endif