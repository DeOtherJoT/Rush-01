/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:46:59 by jthor             #+#    #+#             */
/*   Updated: 2023/09/25 12:47:01 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH2_H
# define RUSH2_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define FALSE 0
# define TRUE 1
# define BUFFER_SIZE 25

typedef struct s_data
{
	int	*answer;
	int	*clues;
	int	edge;
}	t_data;

typedef struct s_cons
{
	int	ctr1;
	int	ctr2;
	int	visible_1;
	int	visible_2;
	int	max1;
	int	max2;
	int	pos_max;
}	t_cons;

// ft_split.c
/**
 * @brief Basic split function that is used to split the clues to individual
 * digits for processing
 * 
 * @param str The program's argument, the string of the border clues.
 * @return char** pointer to a NULL-terminated array of strings.
 */
char	**ft_split(char *str);

// input.c
/**
 * @brief Takes in the border clue string and parses them into a usable int
 * array. Also initialises the answer array and stores them into the t_data
 * struct.
 * 
 * @param clue_str The border clues passed in as the program's argument.
 * @return Pointer to the t_data struct that holds all vital data.
 */
t_data	*parse_input(char *clue_str);

// solver.c
int	constraint_check(int *ans, int *clue, int edge, int place);
/**
 * @brief	Backtracking algorithm to solve the skyscrapers puzzle.
 * 			Target to solve 6x6 in a reasonable time.
 * 
 * @param data		the struct that holds all necessary data
 * @param place 	the current place in the board where the possible
 * 					values are being placed.
 * @return int 	Return TRUE if answer is found, FALSE if no answer is found
 * 				that fulfills the constraints at the current location.
 */
int		solver(t_data *data, int place);

// utils_solver.c
/**
 * @brief	Depending on the flag parameter, locates the position of the
 * 			tallest skyscraper, either in the column or row.
 * 
 * @param answer The answer stored as a 1D array.
 * @param edge The length of one edge of the answer board.
 * @param place The current position to be solved in the answer board.
 * @param flag (1) for column, (2) for row.
 * @return	The position of the tallest skyscraper, imagined as a 0-indexed
 * 			array with respect to the current row or column.
*/
int		get_pos_max(int *answer, int edge, int place, int flag);
/**
 * @brief Initialises the t_cons struct to be used in the constrint check
 * functions.
 * 
 * @param dat Pointer to the t_cons struct.
 * @param edge The size of the grid (aka the length of one edge).
 */
void	set_cons_data(t_cons *dat, int edge);

// utils.c
/**
 * @brief Returns the length of a string passed as the parameter.
 */
size_t	ft_strlen(const char *str);
/**
 * @brief Converts the string passed as the parameter to its integer
 * equivalent.
 */
int		ft_atoi(char *str);
/**
 * @brief Frees the malloc'd t_data struct.
 */
void	ft_free_data(t_data *data);

// utils2.c
/**
 * @brief Notifies the user of what error has occured. Returns the second
 * parameter.
 */
int		ft_error(char *str, int ret);
/**
 * @brief Writes a character to STDOUT.
 */
void	ft_putchar(char c);
/**
 * @brief Writes an integer to STDOUT.
 */
void	ft_putnbr(int nb);
/**
 * @brief Frees a malloc'd array of strings.
 */
void	ft_free_split(char **arr);

// get_next_line
/**
 * @brief Iterates through the fd and returns the next line.
 */
char	*get_next_line(int fd);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
#endif
