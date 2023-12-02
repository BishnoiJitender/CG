#include <iostream>
#include <graphics.h>


void translateRectangle(int &x1, int &y1, int &x2, int &y2, int tx, int ty) {
    x1 = x1 + tx;
    y1 = y1 + ty;
    x2 = x2 + tx;
    y2 = y2 + ty;
}


void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2; 

    std::cout << "Enter the coordinates of the top-left corner (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the bottom-right corner (x2 y2): ";
    std::cin >> x2 >> y2;

    int tx, ty;
    std::cout << "Enter the translation factors (tx ty): ";
    std::cin >> tx >> ty;

    drawRectangle(x1, y1, x2, y2);
    outtextxy(x1 + 5, y1 - 5, "Original Rectangle");


    translateRectangle(x1, y1, x2, y2, tx, ty);

    
    drawRectangle(x1, y1, x2, y2);
    outtextxy(x1 + 5, y1 - 5, "Translated Rectangle");

    getch();
    closegraph();
    return 0;
}

