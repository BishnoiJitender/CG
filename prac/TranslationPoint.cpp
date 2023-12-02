#include <iostream>
#include <graphics.h>


void translatePoint(int &x, int &y, int tx, int ty) {
    x = x + tx;
    y = y + ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x, y;
    std::cout << "Enter the coordinates of the point (x y): ";
    std::cin >> x >> y;

    int tx, ty;
    std::cout << "Enter the translation factors (tx ty): ";
    std::cin >> tx >> ty;

    
    putpixel(x, y, WHITE);
    outtextxy(x + 5, y + 5, "Original Point");

    
    translatePoint(x, y, tx, ty);

    
    putpixel(x, y, RED);
    outtextxy(x + 5, y + 5, "Translated Point");

    getch();
    closegraph();
    return 0;
}

