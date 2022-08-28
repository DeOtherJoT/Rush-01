#include "../includes/rush.h"

int	get_count(char *str, char sep)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		while (*str && (*str == sep))
			str++;
		if (*str)
			ret++;
		while(*str && (*str != sep))
			str++;
	}
	return (ret);
}

char	*get_word(char *str, char sep)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (str[i] != sep)
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] != sep)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char **ft_split(char *str, char sep)
{
	char	**ret;
	int		word_count;
	int		i;

	word_count = get_count(str, sep);
	ret = malloc(sizeof(char *) * (word_count + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*str && (*str == sep))
			str++;
		if (*str)
			ret[i] = get_word(str, sep);
		while (*str && (*str != sep))
			str++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_free_array(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}