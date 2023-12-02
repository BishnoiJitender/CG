#include <iostream>
#include <graphics.h>


void translateTriangle(int x[], int y[], int tx, int ty, int vertices) {
    for (int i = 0; i < vertices; i++) {
        x[i] = x[i] + tx;
        y[i] = y[i] + ty;
    }
}


void drawTriangle(int x[], int y[]) {
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[3], y[3]; 

  
    std::cout << "Enter the coordinates of the first vertex (x1 y1): ";
    std::cin >> x[0] >> y[0];
    std::cout << "Enter the coordinates of the second vertex (x2 y2): ";
    std::cin >> x[1] >> y[1];
    std::cout << "Enter the coordinates of the third vertex (x3 y3): ";
    std::cin >> x[2] >> y[2];

    int tx, ty;
    std::cout << "Enter the translation factors (tx ty): ";
    std::cin >> tx >> ty;

  
    drawTriangle(x, y);
    outtextxy(x[0] + 5, y[0] - 5, "Original Triangle");


    translateTriangle(x, y, tx, ty, 3);

  
    drawTriangle(x, y);
    outtextxy(x[0] + 5, y[0] - 5, "Translated Triangle");

    getch();
    closegraph();
    return 0;
}

