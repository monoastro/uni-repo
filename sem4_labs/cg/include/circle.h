#include <stdio.h>
#include <graphics.h>

void midpointCircle(int xc, int yc, int r)
{
//	int xc, yc, r;
//	printf("Enter the coordinates of the center: ");
//	scanf("%d %d", &xc, &yc);
//	printf("Enter the radius of the circle: ");
//	scanf("%d", &r);

    int x = 0;
    int y = r;
    int p = 1 - r;

    // Plot the initial point in each quadrant
    putpixel(x + xc, y + yc, GREEN);
    putpixel(-x + xc, y + yc, GREEN);
    putpixel(x + xc, -y + yc, GREEN);
    putpixel(-x + xc, -y + yc, GREEN);

    putpixel(y + xc, x + yc, GREEN);
    putpixel(-y + xc, x + yc, GREEN);
    putpixel(y + xc, -x + yc, GREEN);
    putpixel(-y + xc, -x + yc, GREEN);

    while (x++ < y)
	{
        if (p <= 0)
		{
            p = p + 2 * x + 1;
        }
		else
		{
            y--;
            p = p + 2 * (x - y) + 1;
        }

        // All the perimeter points have already been printed
        if (x > y) break;

        // Printing the generated point and its reflection in the other octants
        putpixel(x + xc, y + yc, GREEN);
        putpixel(-x + xc, y + yc, GREEN);
        putpixel(x + xc, -y + yc, GREEN);
        putpixel(-x + xc, -y + yc, GREEN);

        if (x != y)
		{
            putpixel(y + xc, x + yc, GREEN);
            putpixel(-y + xc, x + yc, GREEN);
            putpixel(y + xc, -x + yc, GREEN);
            putpixel(-y + xc, -x + yc, GREEN);
        }
    }
}
