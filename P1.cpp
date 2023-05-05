// Bresenham's Line Drawing Algorithm
#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1, x2, y2;

    cout << "Enter X1-Coordinate: ";
    cin >> x1;

    cout << "Enter Y1-Coordinate: ";
    cin >> y1;

    cout << "Enter X2-Coordinate: ";
    cin >> x2;

    cout << "Enter Y2-Coordinate: ";
    cin >> y2;

    int dy = (y2 - y1);
    int dx = (x2 - x1);
    float m = (y2 - y1) / (x2 - x1);
    float p = 2 * dy - dx;
    int x = x1;
    int y = y1;
    if (m < 1)
    {
        while (x <= x2)
        {
            if (p < 0)
            {
                x+=1;
                p+=2*dy;
            }
            else
            {
                x+=1;
                y+=1;
                p+=2*(dy-dx);
            }
            putpixel(x,y,WHITE);
        }
    }
    else
    {
        while (x <= x2)
        {
            if (p < 0)
            {
                y+=1;
                p+=2*dx;
            }
            else
            {
                x+=1;
                y+=1;
                p+=2*(dx-dy);
            }
            putpixel(x,y,WHITE);
        }
    }

    getch();
    closegraph();
    return 0;
}