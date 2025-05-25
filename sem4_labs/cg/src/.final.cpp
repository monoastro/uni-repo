#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void drawellipse(float, float, int, int);

int main()
{
	int gd, gm;
	// initgraph(&gm, &gm, NULL);
	initwindow(getmaxwidth(), getmaxheight());
	setbkcolor(WHITE);
	setcolor(BLUE);
	cleardevice();
	float Rx, Ry;
	int h, k;
	cout<<"Enter Rx and Ry: ";
	cin>>Rx>>Ry;
	cout<<"Enter center h, k: ";
	cin>>h>>k;
	drawellipse(Rx, Ry, h, k);
	drawellipse(Rx/10, Ry/10, h + Rx, k);
	drawellipse(Rx/10, Ry/10, h - Rx, k);
	drawellipse(Rx/10, Ry/10, h, k + Ry);
	drawellipse(Rx/10, Ry/10, h, k - Ry);
	outtextxy(h+Rx+50, k+Ry+50, "Avignya Gautam.");
	getch();
	closegraph();
	return 0;
}

void drawellipse(float Rx, float Ry, int h, int k)
{
	// Region 1
	int X = 0;
	int Y = Ry;
	int Rx2 = Rx*Rx;
	int Ry2 = Ry*Ry;
	float P = Ry2 - Rx2*Ry + (1/4)*Rx2;
	while((2*Ry2*X) <= (2*Rx2*Y))
	{
		if(P < 0)
		{
			P += 2*Ry2*X + Ry2;
		}
		else
		{
			Y--;
			P += 2*Ry2*X - 2*Rx2*Y + Ry2;
		}
		X++;
		putpixel(X + h, Y + k, BLACK);
		putpixel(X + h, -Y + k, BLACK);
		putpixel(-X + h, Y + k, BLACK);
		putpixel(-X + h, -Y + k, BLACK);

	}
	P = Ry2*pow(X + 0.5, 2) + Rx2*pow(Y - 1, 2) - Rx2*Ry2;
	//Region 2
	while(Y != 0)
	{
		if(P <= 0)
		{
			X++;
			P += 2*Ry2*X - 2*Rx2*Y + Rx2;
		}
		else
		{
			P += Rx2 - 2*Rx2*Y;
		}
		Y--;
		putpixel(X + h, Y + k, BLACK);
		putpixel(X + h, -Y + k, BLACK);
		putpixel(-X + h, Y + k, BLACK);
		putpixel(-X + h, -Y + k, BLACK);
	}
}
