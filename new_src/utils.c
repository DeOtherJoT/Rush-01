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

int	ft_sqrt(int nb)
{
	int	start;
	int	end;
	int	mid;

	if (nb > 0)
	{
		start = 1;
		end = nb;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if ((mid * mid) == nb)
				return (mid);
			else if ((mid * mid) > nb)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
	return (0);
}

void	ft_free_data(t_data *data)
{
	free(data->answer);
	free(data->clues);
	free(data);
}