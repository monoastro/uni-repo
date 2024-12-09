#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

#define PI 3.1415926535889
//translates the coordinates to the new axes
void axes();
void translateAxes(int *x, int *y);
void drawTriangle(int coordinates[3][2]);
void drawObject(unsigned num_points, int coordinates[][2]);
#endif 

