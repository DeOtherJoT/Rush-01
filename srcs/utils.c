#include "../includes/rush2.h"

size_t	ft_strlen(char *str)
{
	size_t ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	neg = 1;
	while (*str && *str == ' ')
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	res = 0;
	while(*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

void	ft_free_data(t_data *data)
{
	free(data->answer);
	free(data->clues);
	free(data);
}