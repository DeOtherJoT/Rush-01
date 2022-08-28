#include "../includes/rush.h"

int	check_double(int puzzle[4][4], int pos, int num)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
	{
		if (puzzle[i][pos % 4] == num)
			return (1);
	}
	i = -1;
	while (++i < pos % 4)
	{
		if (puzzle[pos / 4][i] == num)
			return (1);
	}
	return (0);
}

int	check_col_up(int puzzle[4][4], int pos, int clue[16])
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (puzzle[i][pos % 4] > max)
			{
				max = puzzle[i][pos % 4];
				visible++;
			}
			i++;
		}
		if (clue[pos % 4] != visible)
			return (1);
	}
	return (0);
}

int	check_col_down(int puzzle[4][4], int pos, int clue[16])
{
	int	i;
	int	max;
	int	visible;

	i = 3;
	max = 0;
	visible = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (puzzle[i][pos % 4] > max)
			{
				max = puzzle[i][pos % 4];
				visible++;
			}
			i--;
		}
		if (clue[4 + (pos % 4)] != visible)
			return (-1);
	}
	return (0);
}

int	check_row_left(int puzzle[4][4], int pos, int clue[16])
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (puzzle[pos / 4][i] > max)
			{
				max = puzzle[pos / 4][i];
				visible++;
			}
			i++;
		}
		if (clue[8 + (pos / 4)] != visible)
			return (1);
	}
	return (0);
}

int	check_row_right(int puzzle[4][4], int pos, int clue[16])
{
	int	i;
	int	max;
	int	visible;

	i = 4;
	max = 0;
	visible = 0;
	if (pos % 4 == 3)
	{
		while (--i > 0)
		{
			if (puzzle[pos / 4][i] > max)
			{
				max = puzzle[pos / 4][i];
				visible++;
			}
		}
		if (clue[12 + pos / 4] != visible)
			return (1);
	}
	return (0);
}