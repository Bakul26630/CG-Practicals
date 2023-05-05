#include <iostream>
#include <graphics.h>
#include <cmath >
using namespace std;
int main()
{
    int tx = 2, ty = 5;
    int window1 = initwindow(800, 800);
    int i, j, k;
    float P[2][3];
    cout << "Enter the coordinates of line" << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            cin >> P[i][j];
        P[i][j] = 1;
    }

    line(P[0][0], P[0][1], P[1][0], P[1][1]);

    delay(7000);
    float
        pp[2][3] = {0};
    int
        ch;
    cout << "Enter the 2d-transformation" << endl;
    cout << "1.translation \n 2. shearing \n 3.reflection \n 4.rotation \n 5.scaling \n 6.exit " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        cout << "Enter the translating factor" << endl;
        cin >> tx >> ty;
        int T[3][3] = {{1, 0, 0},
                       {0, 1, 0},
                       {tx, ty, 1}};
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
                for (k = 0; k < 3; k++)
                    pp[i][j] += P[i][k] * T[k][j];
        }

        line(pp[0][0], pp[0][1], pp[1][0],
             pp[1][1]);
        system("pause");
        break;
    }
    case 2:
    {
        int sh;
        char ax;

        cout << "Enter the shearing axis " << endl;
        cin >> ax;
        cout << "Enter the shearing factor" << endl;
        if (ax == 'x')
        {
            cin >> sh;
            int T[3][3] = {{1, 0, 0}, {sh, 1, 0}, {0, 0, 1}};
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 3; j++)
                    for (k = 0; k < 3; k++)
                        pp[i][j] += P[i][k] * T[k][j];
            }
            line(pp[0][0], pp[0][1], pp[1][0], pp[1][1]);
            system("pause");
        }
        if (ax == 'y')
        {
            cin >> sh;
            int T[3][3] = {{1, sh, 0}, {0, 1, 0}, {0, 0, 1}};
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 3; j++)
                    for (k = 0; k < 3; k++)
                        pp[i][j] += P[i][k] * T[k][j];
            }
            line(pp[0][0], pp[0][1], pp[1][0], pp[1][1]);
            system("pause");
        }
        break;
    }
    case 3:
    {
        int midx, midy, xn1, yn1, xn2, yn2;
        char ax;
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;
        line(0, midy, midx * 2, midy);
        line(midx, 0, midx, midy * 2);
        cout << "Enter the axis for reflection" << endl;
        cin >> ax;
        if (ax == 'y')
        {
            xn1 = (midx - P[1][0]) + midx;
            yn1 = P[0][1];
            xn2 = (midx - P[0][0]) + midx;
            yn2 = P[1][1];
        }
        if (ax == 'x')
        {
            yn1 = (midy - P[1][1]) + midy;
            xn1 = P[0][0];
            yn2 = (midy - P[0][1]) + midy;
            xn2 = P[1][0];
            cout << xn1 << " " << yn1 << " " << xn2 << " " << yn2 << endl;
        }
        line(xn1, yn1, xn2, yn2);
        system("pause");
        break;
    }
    case 4:
    {
        float theta;
        cout << "Enter the theta for rotation" << endl;

        cin >> theta;
        float rx;
        rx = (theta * 3.14) / 180;
        float T[3][3] = {{cos(rx), sin(rx), 0}, {-sin(rx), cos(rx), 0}, {0, 0, 1}};
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
                for (k = 0; k < 3; k++)

                    pp[i][j] += P[i][k] * T[k][j];
        }
        line(pp[0][0], pp[0][1], pp[1][0], pp[1][1]);
        system("pause");
        break;
    }
    case 5:
    {
        int Sx, Sy;
        cout << "Enter the scaling factor for x-axis" << endl;
        cin >> Sx;
        cout << "Enter the scaling factor for y -axis" << endl;
        cin >> Sy;
        int T[3][3] = {{Sx, 0, 1}, {0, Sy, 1}, {0, 0, 1}};
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
                for (k = 0; k < 3; k++)
                    pp[i][j] += P[i][k] * T[k][j];
        }
        line(pp[0][0], pp[0][1], pp[1][0], pp[1][1]);
        system("pause");
        break;
    }
    }
    return 0;
}
