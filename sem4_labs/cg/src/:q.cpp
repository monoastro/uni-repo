#include <graphics.h>
#include <iostream>
 
using namespace std;
 
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
 
int xmin, ymin, xmax, ymax;
 
int computeCode(int x, int y) {
    int code = INSIDE;
 
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
 
    return code;
}
 
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;
 
    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints lie inside the rectangle
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the rectangle in the same region
            break;
        } else {
            // Some segment of the line needs clipping
            int codeOut;
            int x, y;
 
            // At least one endpoint is outside the rectangle
            codeOut = code1 ? code1 : code2;
 
            // Find the intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
 
            // Replace the outside point with the intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
 
    if (accept) {
        setcolor(BLUE);
        line(x1, y1, x2, y2);
    }
}
 
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"NULL");
    setbkcolor(WHITE);
    setcolor(BLACK);
    cleardevice();
 
    //cout << "Enter the coordinates of the clipping window (xmin, ymin, xmax, ymax): "<<endl;
    //cin >> xmin >> ymin >> xmax >> ymax;
 
    rectangle(xmin, ymin, xmax, ymax);
 
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the line (x1, y1, x2, y2): "<<endl;
    cin >> x1 >> y1 >> x2 >> y2;
 
    setcolor(RED);
    line(x1, y1, x2, y2);
 
    cohenSutherlandClip(x1, y1, x2, y2);
 
 	outtextxy(450, 450, "080BEI008");
	getch();
    closegraph();
 
 
    return 0;
}
