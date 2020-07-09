#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

char cube_hole(int i, int j, int size);
/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of Menger Sponge to draw
 * Return: 1 on success, 0 on failure
 */
void menger(int level)
{

	int i, j, size;

	if (level < 0)
		exit(0);
	else
	{
		size = pow(3, level);

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				putchar(cube_hole(i, j, size / 3));
			}
			printf("\n");
		}
	}
}

/**
 * cube_hole - finds where hole is in cube representation
 * @i: current row
 * @j: current column
 * @size: cube root of size of cube
 * Return: # char for printing if no hole, or a space char if hole
 */
char cube_hole(int i, int j, int size)
{
	if (size == 0)
		return ('#');
	if ((i % (size * 3)) / size == 1)
		if ((j % (size * 3)) / size == 1)
			return (' ');
	return (cube_hole(i, j, size / 3));
}
