#include "graphics.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>




void Bresenham_line_draw(int x1, int y1, int x2, int y2) {

    int x = x1;
    int y = y1;

    int dx = x2 - x1;
    int dy = y2 - y1;

    if ((dy / dx) < 1) {

        int p = 2 * dy - dx;

        while (x <= x2) {

            putpixel(x, y, 15);
            x++;

            if (p < 0) {
                p += 2 * dy;
            }
            else {

                p += (2 * dy - 2 * dx);
                y++;
            }
        }
    }
    else {

        int p = 2 * dx - dy;

        while (x <= x2) {
            putpixel(x, y, 15);
            x++;

            if (p < 0) {
                p += 2 * dy;
            }
            else {
                p += 2 * dy - 2 * dx;
                y++;
            }
        }
    }

}

int main() {

    int x1=10;
    int y1=200;
    int x2=20;
    int y2=50000;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //printf("Enter the coordinates of the starting and ending points\n");
    //scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

    Bresenham_line_draw(x1, y1, x2, y2);
    getch();

    closegraph();
    return 0;
}