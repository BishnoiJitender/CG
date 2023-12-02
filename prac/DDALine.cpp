#include <iostream>
#include <cmath>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / static_cast<float>(steps);
    float yIncrement = static_cast<float>(dy) / static_cast<float>(steps);

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
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

    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

