#include <stdio.h>

#define fn(x, y) (x + y)

int main() {
	float x0, y0, h, xn;
	printf("Enter the value of x0, y0, h, xn: ");
	scanf("%f %f %f %f", &x0, &y0, &h, &xn);
	while (x0 < xn) {
		float k1 = h * fn(x0, y0);
		float k2 = h * fn(x0 + h / 2, y0 + k1 / 2);
		float k3 = h * fn(x0 + h / 2, y0 + k2 / 2);
		float k4 = h * fn(x0 + h, y0 + k3);
		y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		x0 += h;
	}
	printf("The value of y(%f) is %f\n", xn, y0);
	return 0;
}
