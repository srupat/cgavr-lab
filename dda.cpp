#include "graphics.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



void draw_line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float x = x1, y = y1;
    float slope = (float)dy / dx;

    // Determine the number of steps needed
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    // Set the initial point
    putpixel(x, y, WHITE);

    // Draw the line
    if (slope < 1) {
        if (x1 < x2) {
            for (k = 0; k < steps; k++) {
                x += 1;
                y += slope;
                putpixel(round(x), round(y), WHITE);
                
            }
        }
        else {
            for (k = 0; k < steps; k++) {
                x -= 1;
                y -= slope;
                putpixel(round(x), round(y), WHITE);
                //getch();
            }
        }
    }
    else {
        if (y1 < y2) {
            for (k = 0; k < steps; k++) {
                x += 1 / slope;
                y += 1;
                putpixel(round(x), round(y), WHITE);
                
            }
        }
        else {
            for (k = 0; k < steps; k++) {
                x -= 1 / slope;
                y -= 1;
                putpixel(round(x), round(y), WHITE);
                
            }
        }
    }
}

void draw_dotted_line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float x = x1, y = y1;
    float slope = (float)dy / dx;

    // Determine the number of steps needed
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    // Set the initial point
    putpixel(x, y, WHITE);

    // Draw the line
    if (slope < 1) {
        if (x1 < x2) {
            for (k = 0; k < steps; k++) {
                
                x += 10;
                y += slope;
                putpixel(round(x), round(y), WHITE);

            }
        }
        else {
            for (k = 0; k < steps; k++) {
                x -= 10;
                y -= slope;
                putpixel(round(x), round(y), WHITE);
                //getch();
            }
        }
    }
    else {
        if (y1 < y2) {
            for (k = 0; k < steps; k++) {
                x += 1 / slope;
                y += 10;
                putpixel(round(x), round(y), WHITE);

            }
        }
        else {
            for (k = 0; k < steps; k++) {
                x -= 1 / slope;
                y -= 10;
                putpixel(round(x), round(y), WHITE);

            }
        }
    }
}



int main() {

    int x1 = 30, y1 = 100;   // Starting point coordinates
    int x2 = 300, y2 = 300;   // Ending point coordinates

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    draw_dotted_line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}