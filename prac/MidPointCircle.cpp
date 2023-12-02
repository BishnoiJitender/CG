#include <iostream>
#include <graphics.h>

void drawCircleMidpoint(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius; 

  
    putpixel(x + xc, y + yc, WHITE);
    putpixel(-x + xc, y + yc, WHITE);
    putpixel(x + xc, -y + yc, WHITE);
    putpixel(-x + xc, -y + yc, WHITE);

   
    if (radius > 0) {
        putpixel(y + xc, x + yc, WHITE);
        putpixel(-y + xc, x + yc, WHITE);
        putpixel(y + xc, -x + yc, WHITE);
        putpixel(-y + xc, -x + yc, WHITE);
    }


    int decision = 0;

    while (y > x) {
        x++;

       
        if (p <= 0)
            p = p + 2 * x + 1;

      
        else {
            y--;
            p = p + 2 * (x - y) + 1;
        }

       
        if (x < y)
        {
            putpixel(x + xc, y + yc, WHITE);
            putpixel(-x + xc, y + yc, WHITE);
            putpixel(x + xc, -y + yc, WHITE);
            putpixel(-x + xc, -y + yc, WHITE);
        }

 
        if (x != y)
        {
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

    drawCircleMidpoint(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

