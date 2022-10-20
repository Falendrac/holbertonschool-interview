#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 *
 * @level: The level of the Menger Sponge to draw.
 *
 */
void menger(int level)
{
	int row, column, height, width, gap, limit;

	limit = pow(3, level);
	for (row = 0; row < limit; row++)
	{
		for (column = 0; column < limit; column++)
		{
			gap = 0;
			height = row;
			width = column;

			while (height > 0)
			{
				if (height % 3 == 1 && width % 3 == 1)
					gap = 1;
				height /= 3;
				width /= 3;
			}
			if (gap == 0)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
