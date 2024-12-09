#include "labs.h"
#include "definitions.h"

int main()
{	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	setcolor(GREEN);
	
	lab2();

	getch();
	closegraph();
	return 0;
}

void car()
{
	int car[][2] =
	{
		{0, 0},
		{0, 30},
		{-30, 30},
		{-30, 60},
		{-90, 60},
		{-90, 30},
		{-90, 30},
		{-120, 30},
		{-120, 0},
	};
	unsigned size = sizeof(car)/sizeof(car[0]);
	drawObject(size, car);
	int wheelCoords[] = { -30, 0, 10 };
	int wheelCoords2[] = { -90, 0, 10 };
	translateAxes(&wheelCoords[0], &wheelCoords[1]);
	translateAxes(&wheelCoords2[0], &wheelCoords2[1]);

	//draw road
	// translation stuff
	for(size_t i = 0; i<200; i++)
	{
		cleardevice();
		translate(size, car, 1, 0);
		translateArr(1, wheelCoords, 1);
		translateArr(1, wheelCoords2, 1);
		circle(wheelCoords[0], wheelCoords[1], wheelCoords[2]);
		circle(wheelCoords2[0], wheelCoords2[1], wheelCoords2[2]);
		drawObject(size, car);
		line(0, HEIGHT/2, WIDTH, HEIGHT/2);
		line(0, HEIGHT/2 + 30, WIDTH, HEIGHT/2 + 30);
		delay(10);
	}
	delay(500);
}

void lab5()
{
	//coordinates of a triangle in the first quadrant	
	int triangle[3][2] = 
	{
		{-50, 0},
		{-100, -100},
		{-50, -100 }
	};
	int axis[2] = {0, 0};

	//translation stuff
	cleardevice();
	outtextxy(WIDTH/2, 10, "Translation");
	drawTriangle(triangle);
	translate(3, triangle, 100, 0);
	drawTriangle(triangle);
	delay(2000);

	// smooth translation
	/*
	for(size_t i = 0; i<200; i++)
	{
		cleardevice();
		outtextxy(WIDTH/2, 10, "Translation");
		translate(3, triangle, 1, 0);
		drawTriangle(triangle);
		delay(10);
	}
	*/


	//scaling stuff
	cleardevice();
	outtextxy(WIDTH/2, 10, "Scaling");
	drawTriangle(triangle);
	scale(3, triangle, 0.6, 0.6, axis);
	drawTriangle(triangle);
	delay(2000);

	//shearing stuff
	cleardevice();
	outtextxy(WIDTH/2, 10, "Shearing");
	/*
	shearY(3, triangle, 2, triangle[1][0]);
	drawTriangle(triangle);
	delay(2000);
	*/

	int square[][2] = 
	{
		{0, 0},
		{100, 0},
		{100, 50},
		{0, 50}
	};
	drawObject(4, square);
	delay(1000);

	shearX(4, square, 2, 0);
	drawObject(4, square);
	delay(1000);
	cleardevice();

	//for(size_t i = 0; i<3; i++) printf("%d %d\n", triangle[i][0], triangle[i][1]);
	//for(size_t i = 0; i<4; i++) printf("%d %d\n", square[i][0], square[i][1]);
}

void lab4()
{	
	axes();
	//coordinates of a triangle in the first quadrant
	int triangle[3][2] = 
	{
		{50, 50},
		{50, 200},
		{200, 50}
	};
	//draw the triangle in the first quadrant 
	drawTriangle(triangle);
	
	//REFLECTION stuff reflect the triangle with respect to the x-axis
	reflectXaxis(3, triangle);
	drawTriangle(triangle);
	//reflect the above triangle with respect to the y-axis
	reflectYaxis(3, triangle);
	drawTriangle(triangle);

	//reflect the above triangle with respect to the x-axis
	reflectXaxis(3, triangle);
	drawTriangle(triangle);

	//reflect once again to get the original triangle
	reflectYaxis(3, triangle);
	setcolor(RED);
	drawTriangle(triangle);

	//ROTATION stuff
	setcolor(BLUE);
	int axis[2] = {50, 50};
	printf("%u %u\n", axis[0], axis[1]);
	float theta = -60.f;
	rotate(3, triangle, theta, axis);
	drawTriangle(triangle);
}

void lab3()
{
	midpointEllipse(WIDTH/2, HEIGHT/2, WIDTH/4, HEIGHT/8);
}

void lab2()
{
	//draw a diamond using bla
	drawLineBresenham(0, HEIGHT/2, WIDTH/2, HEIGHT);
	//drawLineBresenham(WIDTH/2, 0, WIDTH, HEIGHT/2);
	//drawLineBresenham(0, HEIGHT/2, WIDTH/2, HEIGHT);
	//drawLineBresenham(WIDTH/2, HEIGHT, WIDTH, HEIGHT/2);

	//draw a circle using mid point
	midpointCircle(WIDTH/2, HEIGHT/2, WIDTH / 4);
}
