#include "../includes/rush.h"

int	check_case(int puzzle[4][4], int pos, int clue[16], int value)
{
	if (check_double(puzzle, pos, value) == 1)
		return (1);
	if (check_top(puzzle, pos, clue) == 1)
		return (1);
	if (check_bottom(puzzle, pos, clue) == 1)
		return (1);
	if (check_left(puzzle, pos, clue) == 1)
		return (1);
	if (check_right(puzzle, pos, clue) == 1)
		return (1);
	return (0);
}

int	solution(int puzzle[4][4], int clue[16], int pos)
{
	int	value;

	if (pos == 16)
		return (1);
	value = 1;
	while (value <= 4)
	{
		puzzle[pos / 4][pos % 4] = value;
		if (check_case(puzzle, pos, clue, value) == 0)
		{
			if (solution(puzzle, clue, pos + 1) == 1)
				return (1);
		}
		else
			puzzle[pos / 4][pos % 4] = 0;
		value++;
	}
	return (0);
}