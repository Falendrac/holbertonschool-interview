#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * compute_sandpiles - Computes two sandpiles
 *
 * @grid1: First grid
 * @grid2: Second grid
 *
 */
void compute_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			grid1[row][column] += grid2[row][column];
			grid2[row][column] = 0;
		}
	}
}

/**
 * is_stabilized - Check if a sandpiles is stabilized or not
 *
 * @grid: Grid of sandpiles we check
 * Return: 0 if is not stabilized, 1 otherwise
 */
int is_stabilized(int grid[3][3])
{
	int first_element = 3;
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > first_element)
				return (0);
		}
	}

	return (1);
}

/**
 * stabilized_sandpiles - Transmit grains at position row/column
 *
 * @grid: The second sandpiles to transmit the grains
 * @row: The current row position
 * @column: The current column position
 */
void stabilized_sandpiles(int grid[3][3], int row, int column)
{
	grid[row][column] -= 4;

	if (row > 0)
		grid[row - 1][column]++;
	if (row < 2)
		grid[row + 1][column]++;
	if (column > 0)
		grid[row][column - 1]++;
	if (column < 2)
		grid[row][column + 1]++;
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * and stabilize the sandpiles
 *
 * @grid1: First sandpiles
 * @grid2: Second sandpiles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	compute_sandpiles(grid1, grid2);

	while (!is_stabilized(grid1))
	{
		printf("=\n");
		print_grid(grid1);

		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				if (grid1[row][column] > 3)
					stabilized_sandpiles(grid2, row, column);
			}
		}

		compute_sandpiles(grid1, grid2);
	}
}
