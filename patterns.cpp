#include "graphics.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>


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

void upperSemiCircle(int xc, int yc, int x, int y)
{
	putpixel(xc - y, yc - x, 15); 
	putpixel(xc - x, yc - y, 15); 
	putpixel(xc + x, yc - y, 15); 
	putpixel(xc + y, yc - x, 15); 
}

void leftSemiCircle(int xc, int yc, int x, int y)
{
	putpixel(xc - x, yc - y, 15); 
	putpixel(xc - y, yc - x, 15); 
	putpixel(xc - y, yc + x, 15); 
	putpixel(xc - x, yc + y, 15); 
}

void rightSemiCircle(int xc, int yc, int x, int y)
{
	putpixel(xc + x, yc - y, 15); 
	putpixel(xc + y, yc - x, 15); 
	putpixel(xc + y, yc + x, 15); 
	putpixel(xc + x, yc + y, 15); 
}

void bottomSemiCircle(int xc, int yc, int x, int y)
{
	putpixel(xc - y, yc + x, 15); 
	putpixel(xc - x, yc + y, 15); 
	putpixel(xc + x, yc + y, 15); 
	putpixel(xc + y, yc + x, 15); 
}
void pattern1(int xc, int yc, int r)
{
	// first crest
	int x = 0, y = r;
	int p = 3 - 2 * r;
	upperSemiCircle(xc, yc, x, y);
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
		upperSemiCircle(xc, yc, x, y);
		delay(50);
	}

	//first trough
	int x1 = 0, y1 = r;
	int p1 = 3 - 2 * r;
	bottomSemiCircle(xc + 2*r, yc, x1, y1);
	while (y1 >= x1)
	{

		x1++;

		if (p1 > 0)
		{
			y1--;
			p1 = p1 + 4 * (x1 - y1) + 10;
		}
		else
			p1 = p1 + 4 * x1 + 6;
		bottomSemiCircle(xc + 2*r, yc, x1, y1);
		delay(50);
	}

	//second crest
	int x2 = 0, y2 = r;
	int p2 = 3 - 2 * r;
	upperSemiCircle(xc + 4*r, yc, x2, y2);
	while (y2 >= x2)
	{

		x2++;

		if (p2 > 0)
		{
			y2--;
			p2 = p2 + 4 * (x2 - y2) + 10;
		}
		else
			p2 = p2 + 4 * x2 + 6;
		upperSemiCircle(xc + 4*r, yc, x2, y2);
		delay(50);
	}

	//second trough
	int x3 = 0, y3 = r;
	int p3 = 3 - 2 * r;
	bottomSemiCircle(xc + 6 * r, yc, x3, y3);
	while (y3 >= x3)
	{

		x3++;

		if (p3 > 0)
		{
			y3--;
			p3 = p3 + 4 * (x3 - y3) + 10;
		}
		else
			p3 = p3 + 4 * x3 + 6;
		bottomSemiCircle(xc + 6 * r, yc, x3, y3);
		delay(50);
	}

}

void pattern2(int xc, int yc, int r)
{
	//upper semi-circle
	int x = 0, y = r;
	int p = 3 - 2 * r;
	upperSemiCircle(xc, yc, x, y);
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
		upperSemiCircle(xc, yc, x, y);
		delay(50);
	}

	// right semi-circle
	int x1 = 0, y1 = r;
	int p1 = 3 - 2 * r;
	rightSemiCircle(xc+r, yc+r, x1, y1);
	while (y1 >= x1)
	{

		x1++;

		if (p1 > 0)
		{
			y1--;
			p1 = p1 + 4 * (x1 - y1) + 10;
		}
		else
			p1 = p1 + 4 * x1 + 6;
		rightSemiCircle(xc+r, yc+r, x1, y1);
		delay(50);
	}

	//bottom semi-circle
	int x2 = 0, y2 = r;
	int p2 = 3 - 2 * r;
	bottomSemiCircle(xc, yc+2*r, x2, y2);
	while (y2 >= x2)
	{

		x2++;

		if (p2 > 0)
		{
			y2--;
			p2 = p2 + 4 * (x2 - y2) + 10;
		}
		else
			p2 = p2 + 4 * x2 + 6;
		bottomSemiCircle(xc, yc+2*r, x2, y2);
		delay(50);
	}

	// left semi circle
	int x3 = 0, y3 = r;
	int p3 = 3 - 2 * r;
	leftSemiCircle(xc-r, yc+r, x3, y3);
	while (y3 >= x3)
	{

		x3++;

		if (p3 > 0)
		{
			y3--;
			p3 = p3 + 4 * (x3 - y3) + 10;
		}
		else
			p3 = p3 + 4 * x3 + 6;
		leftSemiCircle(xc-r, yc+r, x3, y3);
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

void pattern3(int xc, int yc, int r)
{
	int i = 1;
	
	
	// first semicircle
	while (i <= 8) {
		if (i > 1)
			r = r * 1.2;
		int x = 0, y = r;
		int p = 3 - 2 * r;
		
		upperSemiCircle(xc, yc, x, y);
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
			upperSemiCircle(xc, yc, x, y);
			delay(50);
		}
		
		r = r * 1.2;
		
		int x2 = 0, y2 = r;
		int p2 = 3 - 2 * r;
		
		bottomSemiCircle(xc+r/2, yc, x2, y2);
		while (y2 >= x2)
		{

			x2++;

			if (p2 > 0)
			{
				y2--;
				p2 = p2 + 4 * (x2 - y2) + 10;
			}
			else
				p2 = p2 + 4 * x2 + 6;
			bottomSemiCircle(xc+r/2, yc, x2, y2);
			delay(50);
		}
		i++;
		
	}
}


int main()
{
	int xc = 70, yc = 70, r = 10;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ""); 
	//pattern1(xc, yc, r);
	//pattern2(xc, yc, r);
	//pattern3(xc, yc, r);
	circleBres(xc, yc, r);
	getch();
	return 0;
}
