#include <iostream>
#include <graphics.h>

void drawLineMidpoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;

    int d = 2 * dy - dx;
    int deltaE = 2 * dy;
    int deltaNE = 2 * (dy - dx);

    putpixel(x, y, WHITE);

    while (x < x2) {
        if (d <= 0) {
            d += deltaE;
            x++;
        } else {
            d += deltaNE;
            x++;
            y++;
        }

        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    std::cout << "Enter the coordinates of the starting point (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the ending point (x2 y2): ";
    std::cin >> x2 >> y2;

    drawLineMidpoint(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

