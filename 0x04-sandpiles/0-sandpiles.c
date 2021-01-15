#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"
/**
 * print_grid - print a grid
 * @grid: sandpile
 *
 * Return: nothing
 */
void print_grid(int grid[3][3])
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
 * maxgrid - the max of grid
 * @grid: the grid
 * Return: max of the grid
 */
int maxgrid(int grid[3][3])
{
	int i, j;
	int max = grid[0][0];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (max < grid[i][j])
				max = grid[i][j];
	return (max);
}
/**
 * add - add grid 2 to grid1
 * @grid1: first grid
 * @grid2: second grid
 *
 *
 */
void add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 *
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	add(grid1, grid2);
	while (maxgrid(grid1) > 3)
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid2[i][j] = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid2[i][j] += grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid2[i - 1][j] += 1;
					if (j - 1 >= 0)
						grid2[i][j - 1] += 1;
					if (i + 1 <= 2)
						grid2[i + 1][j] += 1;
					if (j + 1 <= 2)
						grid2[i][j + 1] += 1;
				}
				else
					grid2[i][j] += grid1[i][j];
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = grid2[i][j];
			}
		}
	}
}
