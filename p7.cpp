#include <iostream>
#include <graphics.h>
#include <cmath> 
using namespace std;
int maxx,maxy, midx,midy;
int main()
{
    int window1 = initwindow(800, 800);
    bar3d(270, 200, 370, 300, 50, 5);
    int ch, i, j, k;
    int pp[4][4];
    cout << "Select Your Choice for 3d Transformation\n";
    cout << "1.Translate\n2.Scale\n3.Rotation along xaxis\n4.shearing\n";
    cin >> ch;
    cleardevice();
    switch (ch)
    {
    case 1:
    {
        int tx, ty;
        cout << "Enter the translation factor for x,y axis" << endl;
        cin >> tx >> ty;
        bar3d(270 + tx, 200 + ty, 370 + tx, 300 + ty, 50, 5);
        delay(7000);
        cleardevice();
        outtextxy(10, 20, "Parallel projection side view");
        bar3d(0, 200 + ty, 0, 300 + ty, 50, 5);

        delay(7000);
        delay(7000);
        break;
    }
    case 2:
    {
        int sx, sy;
        cout << "Enter the scaling factor for x,y axis" << endl;
        cin >> sx >> sy;
        bar3d(270 * sx, 200 * sy, 370 * sx, 300 * sy, 50, 5);
        delay(7000);
        cleardevice();
        outtextxy(10, 20, "Parallel projection side view");
        bar3d(0, 200 * sy, 0, 300 * sy, 50, 5);

        delay(7000);
        break;
    }
    case 4:
    {
        int shx, shy;
        cout << "Enter the shearing factor for x,y axis" << endl;
        cin >> shx >> shy;
        bar3d(270, 200 + (shy * 270), 370, 300 + (shy * 50), 50 + (270 * shx), 5);
        delay(7000);
        break;
    }
    case 3:
    {
        int ang;
        cout << "Enter the rotation angle" << endl;
        cin >> ang;
        ang = (ang * 3.14) / 180;
        int x1 = 200 * cos(ang) - 50 * sin(ang);
        int y1 =
            50 * cos(ang) + 200 * sin(ang);
        int
            x2 = 300 * cos(ang) - 500 * sin(ang);
        int y2 = 50 * cos(ang) + 300 * sin(ang);
        bar3d(x1, y1, x2, y2, 50, 5);
        delay(7000);
        break;
    }
    }
    return 0;
}