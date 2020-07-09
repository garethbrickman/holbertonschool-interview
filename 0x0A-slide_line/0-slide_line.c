#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"


void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);
/**
 * slide_line - slides and merges an array of integers
 * @line: ptr array of ints containing size elements
 * @size: size of array
 * @direction: int direction elements must be slid and merged to
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);
	if (direction == 76)
		slide_left(line, size);
	if (direction == 82)
		slide_right(line, size);
	else
		return (0);
	return (1);
}

/**
 * slide_left - slides line left
 * @line: list of ints
 * @size: size of list
 */
void slide_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				i--;
				break;
			}
			if (line[i] == line[j] && line[i] != 0)
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else if (line[j] != 0 && line[i + 1] == 0)
			{
				line[i + 1] = line[j];
				line[j] = 0;
				break;
			}
		}
	}
}

/**
 * slide_right - slides line right
 * @line: list of ints
 * @size: size of list
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = i + 1; j <= size; j++)
		{
			if (line[size - i] == 0 && line[size - j] != 0)
			{
				line[size - i] = line[size - j];
				line[size - j] = 0;
				i--;
				break;
			}
			if (line[size - i] == line[size - j] && line[size - i] != 0)
			{
				line[size - i] *= 2;
				line[size - j] = 0;
				break;
			}
			else if (line[size - j] != 0 && line[size - (i + 1)] == 0)
			{
				line[size - (i + 1)] = line[size - j];
				line[size - j] = 0;
				break;
			}
		}
	}
}
