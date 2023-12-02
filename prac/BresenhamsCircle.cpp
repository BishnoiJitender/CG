#include <iostream>
#include <graphics.h>

void drawCircleBresenham(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius; 

    putpixel(x + xc, y + yc, WHITE);
    putpixel(-x + xc, y + yc, WHITE);
    putpixel(x + xc, -y + yc, WHITE);
    putpixel(-x + xc, -y + yc, WHITE);
    putpixel(y + xc, x + yc, WHITE);
    putpixel(-y + xc, x + yc, WHITE);
    putpixel(y + xc, -x + yc, WHITE);
    putpixel(-y + xc, -x + yc, WHITE);

    while (x <= y) {
        x++;

  
        if (p <= 0)
            p = p + 4 * x + 6;

 
        else {
            y--;
            p = p + 4 * (x - y) + 10;
        }

        if (x <= y) {
            putpixel(x + xc, y + yc, WHITE);
            putpixel(-x + xc, y + yc, WHITE);
            putpixel(x + xc, -y + yc, WHITE);
            putpixel(-x + xc, -y + yc, WHITE);
        }

    
        if (x != y) {
            putpixel(y + xc, x + yc, WHITE);
            putpixel(-y + xc, x + yc, WHITE);
            putpixel(y + xc, -x + yc, WHITE);
            putpixel(-y + xc, -x + yc, WHITE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, radius;
    std::cout << "Enter the center coordinates (xc yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the radius: ";
    std::cin >> radius;

    drawCircleBresenham(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

