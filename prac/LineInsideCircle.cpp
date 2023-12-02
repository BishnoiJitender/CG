#include <iostream>
#include <cmath>
#include <graphics.h>


void drawLineInsideCircle(int xc, int yc, int radius) {
    int x1, y1, x2, y2;

    
    x1 = xc - radius / 2;
    y1 = yc;
    x2 = xc + radius / 2;
    y2 = yc;

    
    circle(xc, yc, radius);

    
    line(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, radius;
    
    std::cout << "Enter the center coordinates of the circle (xc yc): ";
    std::cin >> xc >> yc;
    
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    drawLineInsideCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

