#include "graphics.h"
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>

void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc + x, yc + y, 15);
	putpixel(xc - x, yc + y, 15);
	putpixel(xc + x, yc - y, 15);
	putpixel(xc - x, yc - y, 15);
	putpixel(xc + y, yc + x, 15);
	putpixel(xc - y, yc + x, 15);
	putpixel(xc + y, yc - x, 15);
	putpixel(xc - y, yc - x, 15);
}

void midPoint(int xc, int yc, int r)
{
	int x = 0, y = r;
	int p = 1 - r;
	while (y >= x)
	{
		if (p < 0)
		{
			p = p + 2 * x + 1;
			x++;
		}
		else {
			p = p + 2 * x - 2 * y + 1;
			x++;
			y--;
		}
		drawCircle(xc, yc, x, y);
		delay(50);
	}
}

void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int p = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{

		x++;

		if (p > 0)
		{
			y--;
			p = p + 4 * (x - y) + 10;
		}
		else
			p = p + 4 * x + 6;
		drawCircle(xc, yc, x, y);
		delay(50);
	}
}

int main()
{
	int xc = 70, yc = 70, r = 50;
	int xc1 = 200, yc1 = 70, r1 = 50;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	midPoint(xc, yc, r);
	circleBres(xc1, yc1, r1);
	getch();
	return 0;
}