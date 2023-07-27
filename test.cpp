#include <stdio.h>
#include "graphics.h"
#include <math.h>

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int radius = 10;
    float angle = 0;

    // Number of revolutions for the spiral
    int revolutions = 5;
    int maxRadius = 100;
    int numLines = 500;

    for (int i = 0; i < numLines; i++) {
        int x1 = centerX + radius * cos(angle);
        int y1 = centerY + radius * sin(angle);

        // Update the angle and radius for the next line
        angle += 2 * M_PI * revolutions / numLines;
        radius += maxRadius / numLines;

        int x2 = centerX + radius * cos(angle);
        int y2 = centerY + radius * sin(angle);

        line(x1, y1, x2, y2);
    }

    delay(5000); // Wait for 5 seconds before closing the window
    closegraph();
    return 0;
}
