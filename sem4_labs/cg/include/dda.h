#include <stdio.h>
#include <graphics.h>
#include <math.h>

void dda()
{
	int x1, y1, x2, y2, dx, dy, steps;
	float x, y, x_inc, y_inc;

	printf("Enter the coordinates of the first point: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the coordinates of the second point: ");
	scanf("%d %d", &x2, &y2);


	dx = x2 - x1;
	dy = y2 - y1;

	steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));

	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;

	x = x1;
	y = y1;


	for (int i = 0; i < steps + 1; i++)
	{
		putpixel(round(x), round(y), GREEN);
		x += x_inc;
		y += y_inc;
	}
};
