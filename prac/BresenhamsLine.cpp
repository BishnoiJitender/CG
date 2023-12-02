#include <iostream>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int twoDx = 2 * dx;
    int twoDxMinusDy = 2 * (dx - dy);

    int x, y, p;

    if (dx > dy) {
        if (x1 > x2) {
            x = x2;
            y = y2;
            x2 = x1;
        } else {
            x = x1;
            y = y1;
        }

        putpixel(x, y, WHITE);

        p = 2 * dy - dx;

        while (x < x2) {
            x++;

            if (p < 0) {
                p += twoDy;
            } else {
                if ((x1 < x2 && y1 < y2) || (x1 > x2 && y1 > y2)) {
                    y++;
                } else {
                    y--;
                }
                p += twoDyMinusDx;
            }

            putpixel(x, y, WHITE);
        }
    } else {
        if (y1 > y2) {
            x = x2;
            y = y2;
            y2 = y1;
        } else {
            x = x1;
            y = y1;
        }

        putpixel(x, y, WHITE);

        p = 2 * dx - dy;

        while (y < y2) {
            y++;

            if (p < 0) {
                p += twoDx;
            } else {
                if ((x1 < x2 && y1 < y2) || (x1 > x2 && y1 > y2)) {
                    x++;
                } else {
                    x--;
                }
                p += twoDxMinusDy;
            }

            putpixel(x, y, WHITE);
        }
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

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

