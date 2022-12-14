#include "../includes/rush.h"

int	check_case(int puzzle[4][4], int pos, int clue[16])
{
	if (check_row_left(puzzle, pos, clue) == 1)
		return (1);
	if (check_row_right(puzzle, pos, clue) == 1)
		return (1);
	if (check_col_down(puzzle, pos, clue) == 1)
		return (1);
	if (check_col_up(puzzle, pos, clue) == 1)
		return (1);
	return (0);
}

int	solution(int puzzle[4][4], int clue[16], int pos)
{
	int	value;

	if (pos == 16)
		return (1);
	value = -1;
	while (++value < 4)
	{
		if (check_double(puzzle, pos, value) == 0)
		{
			puzzle[pos / 4][pos % 4] = value;
			if (check_case(puzzle, pos, clue) == 0)
			{
				if (solution(puzzle, clue, pos + 1) == 1)
					return (1);
			}
			else
				puzzle[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}