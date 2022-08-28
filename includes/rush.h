#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

// Main
void	display_solution(int puzzle[4][4]);
int		check_split(char **arr);
int		*clue_init(char *str);

// Solution
int		check_case(int puzzle[4][4], int pos, int clue[16]);
int		solution(int puzzle[4][4], int clue[16], int pos);

// Constraints
int		check_double(int puzzle[4][4], int pos, int num);
int		check_col_up(int puzzle[4][4], int pos, int clue[16]);
int		check_col_down(int puzzle[4][4], int pos, int clue[16]);
int		check_row_left(int puzzle[4][4], int pos, int clue[16]);
int		check_row_right(int puzzle[4][4], int pos, int clue[16]);

// Utils
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

// Utils2 (ft_split)
int		get_count(char *str, char sep);
char	*get_word(char *str, char sep);
char 	**ft_split(char *str, char sep);
void	ft_free_array(char **arr, int len);

#endif