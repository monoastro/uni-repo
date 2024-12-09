#include <math.h>
#include <graphics.h>
#include "definitions.h"

void axes()
{
	//print axes
	line(WIDTH/2, 0, WIDTH/2, HEIGHT);
	line(0, HEIGHT/2, WIDTH, HEIGHT/2);
}

//translates the coordinates to the new axes
void translateAxes(int *x, int *y)
{
	*x = (*x + WIDTH/2);
	*y = (- *y + HEIGHT/2);
}

void drawTriangle(int coordinates[3][2])
{
	//draw functions guarantee that the data received is not modified
	//so work with a copy of the coordinates; it's a pointer
	int copy[3][2];
	for(unsigned i = 0; i<3; i++)
	{
		copy[i][0] = coordinates[i][0];
		copy[i][1] = coordinates[i][1];
	}
	//only needs to be done here
	//translate to the axes defined by the computer
	for(unsigned i = 0; i<3; i++) translateAxes(&copy[i][0], &copy[i][1]);
	//plot the translated points
	for(unsigned i = 0; i<3; i++) line(copy[i][0], copy[i][1], copy[(i+1)%3][0], copy[(i+1)%3][1]);
}
void drawObject(unsigned num_points, int coordinates[][2])
{
	//draw functions guarantee that the data received is not modified
	//so work with a copy of the coordinates; it's a pointer
	int copy[num_points][2];
	for(unsigned i = 0; i<num_points; i++)
	{
		copy[i][0] = coordinates[i][0];
		copy[i][1] = coordinates[i][1];
	}
	//only needs to be done here
	//translate to the axes defined by the computer
	for(unsigned i = 0; i<num_points; i++) translateAxes(&copy[i][0], &copy[i][1]);
	//plot the translated points
	for(unsigned i = 0; i<num_points; i++) line(copy[i][0], copy[i][1], copy[(i+1)%num_points][0], copy[(i+1)%num_points][1]);
}

void reflectXaxis(unsigned num_points, int coordinates[][2])
{
	//make the y coordinates negative
	for(unsigned i = 0; i<num_points; i++) coordinates[i][1] = -coordinates[i][1];
}

void reflectYaxis(unsigned num_points, int coordinates[][2])
{
	//make the x coordinates negative
	for(unsigned i = 0; i<num_points; i++) coordinates[i][0] = -coordinates[i][0];
}

void rotate(unsigned num_points, int coordinates[][2], float theta, int axis[2])
{
    // buffer the coordinates because the updates are simultaneous
    int copy[2];

    // rotate the coordinates by theta degrees
    for (unsigned i = 0; i < num_points; i++)
    {
        copy[0] = axis[0] + (coordinates[i][0] - axis[0]) * cos(theta * PI / 180) - (coordinates[i][1] - axis[1]) * sin(theta * PI / 180);
        copy[1] = axis[1] + (coordinates[i][0] - axis[0]) * sin(theta * PI / 180) + (coordinates[i][1] - axis[1]) * cos(theta * PI / 180);

        // copy the rotated coordinates back to the original array
        coordinates[i][0] = copy[0];
        coordinates[i][1] = copy[1];
    }
}

void scale(unsigned num_points, int coordinates[][2], float sx, float sy, int axis[2])
{
	// scale the coordinates by sx and sy
	for (unsigned i = 0; i < num_points; i++)
	{
		coordinates[i][0] = axis[0] + (coordinates[i][0] - axis[0]) * sx;
		coordinates[i][1] = axis[1] + (coordinates[i][1] - axis[1]) * sy;
	}
}

void shearX(unsigned num_points, int coordinates[][2], float shx, int ref)
{
	//shear the coordinates by shx
	for (unsigned i = 0; i < num_points; i++)
	{
		coordinates[i][0] = coordinates[i][0] + (coordinates[i][1] - ref) * shx;
	}
}

void shearY(unsigned num_points, int coordinates[][2], float shy, int ref)
{
	//shear the coordinates by shy
	for (unsigned i = 0; i < num_points; i++)
	{
		coordinates[i][1] = coordinates[i][1] + (coordinates[i][0] - ref) * shy;
	}
}
void translate(unsigned num_points, int coordinates[][2], int tx, int ty)
{
	// translate the coordinates by tx and ty
	for (unsigned i = 0; i < num_points; i++)
	{
		coordinates[i][0] += tx;
		coordinates[i][1] += ty;
	}
}
void translateArr(unsigned num_points, int points[], int tx)
{
	// translate the coordinates by tx and ty
	for (unsigned i = 0; i < num_points; i++)
	{
		points[i] += tx;
	}
}
