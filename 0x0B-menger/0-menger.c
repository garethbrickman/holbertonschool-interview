#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"


/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of Menger Sponge to draw
 * Return: 1 on success, 0 on failure
 */
void menger(int level)
{
	if (level < 0)
		exit(0);
	else if (level == 0)
		printf("#");
}
