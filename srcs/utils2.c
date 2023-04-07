#include "../includes/rush2.h"

/**
 * @brief	Prints an error message to STDERR
*/

int	ft_error(char *str, int ret)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (ret);
}

/**
 * @brief	Basic putchar function, writes a single character to STDOUT
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * @brief	Basic putnbr function, writes a positive integer to STDOUT
*/

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(48 + nb);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

/**
 * @brief	Frees the array of strings created by the ft_split function
*/

void	ft_free_split(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}