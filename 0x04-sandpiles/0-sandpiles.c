#include "sandpiles.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: stable sandpile
 * @grid2: stable sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	if (!grid1)
	stable_print_grid(grid1);

	if (!grid2)
		stable_print_grid(grid2);
}

/**
 * stable_print_grid - function that prints sandpile grid
 * @grid: input sandpile
  * Return: void
 */
void stable_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

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
