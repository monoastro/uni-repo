#include <graphics.h>
#include <math.h>

void midpointEllipse(int xc, int yc, int a, int b)
{
	int x = 0, y = b, p;
	
	//initial decision parameter
	p = b * b - a * a * b + a * a / 4;
	while (2 * x * b * b < 2 * y * a * a)
	{
		putpixel(xc + x, yc + y, GREEN);
		putpixel(xc - x, yc + y, GREEN);
		putpixel(xc + x, yc - y, GREEN);
		putpixel(xc - x, yc - y, GREEN);
		if (p < 0)
		{
			x = x + 1;
			p = p + 2 * b * b * x + b * b;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + 2 * b * b * x - 2 * a * a * y + b * b;
		}
	}

	p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
	while (y >= 0)
	{
		putpixel(xc + x, yc + y, GREEN);
		putpixel(xc - x, yc + y, GREEN);
		putpixel(xc + x, yc - y, GREEN);
		putpixel(xc - x, yc - y, GREEN);
		if (p > 0)
		{
			y = y - 1;
			p = p - 2 * a * a * y + a * a;
		}
		else
		{
			y = y - 1;
			x = x + 1;
			p = p + 2 * b * b * x - 2 * a * a * y + a * a;
		}
	}
}
