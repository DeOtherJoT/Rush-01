#include "../includes/rush2.h"

static int	get_count(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		ret++;
		while (*str && *str != ' ')
			str++;
	}
	return (ret);
}

static char	*get_word(char *str)
{
	char	*ret;
	int		word_len;
	int		i;

	word_len = 0;
	while (str[word_len] && str[word_len] != ' ')
		word_len++;
	ret = malloc(sizeof(char) * (word_len + 1));
	i = -1;
	while (++i < word_len)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char *str)
{
	char	**ret;
	int		wrd_cnt;
	int		i;

	wrd_cnt = get_count(str);
	ret = malloc(sizeof(char *) * (wrd_cnt + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < wrd_cnt)
	{
		while (*str && *str == ' ')
			str++;
		ret[i] = get_word(str);
		while (*str && *str != ' ')
			str++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}