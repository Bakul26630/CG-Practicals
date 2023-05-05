// Implementing Line-Clipping Algorithm that is Cohen-Sutherland Algorithm
#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

const int Inside = 0;
const int Top = 8;
const int Bottom = 4;
const int Left = 1;
const int Right = 2;

int Compute_Code(double X, double Y, int x_min, int y_min, int x_max, int y_max)
{
    int code = Inside;
    if (X < x_min)
    {
        code |= Left;
    }
    else if (X > x_max)
    {
        code |= Right;
    }

    if (Y < y_min)
    {
        code |= Bottom;
    }
    else if (Y > y_max)
    {
        code |= Top;
    }

    return code;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setcolor(WHITE);
    int Xmin, Xmax, Ymin, Ymax;
    cout << "Enter X-min: ";
    cin >> Xmin;
    cout << "Enter Y-min: ";
    cin >> Ymin;
    cout << "Enter X-max: ";
    cin >> Xmax;
    cout << "Enter Y-max: ";
    cin >> Ymax;
    rectangle(Xmin, Ymin, Xmax, Ymax);

    int lX_min, lY_min, lX_max, lY_max;
    cout << "Enter Line X-min coordinate: ";
    cin >> lX_min;
    cout << "Enter Line y-min coordinate: ";
    cin >> lY_min;
    cout << "Enter Line X-max coordinate: ";
    cin >> lX_max;
    cout << "Enter Line Y-max coordinate: ";
    cin >> lY_max;

    int regionCode[2];
    regionCode[0] = Compute_Code(lX_min, lY_min, Xmin, Ymin, Xmax, Ymax);
    regionCode[1] = Compute_Code(lX_max, lY_max, Xmin, Ymin, Xmax, Ymax);

    bool accept = false;
    
    while (true)
    {
        if (regionCode[0] == 0 && regionCode[1] == 0)
        {
            cout << "\nCompletely Visible";
            line(lX_min, lY_min, lX_max, lY_max);
            accept=true;
            break;
        }
        else
        {
            if (!(regionCode[0] & regionCode[1]))
            {
                cout << "\nLine partially clipped";
                double X, Y;
                int code_out;
                float m = (lY_max - lY_min) / (lX_max - lX_min);
                if (regionCode[0] != 0)
                {
                    code_out = regionCode[0];
                }
                else
                {
                    code_out = regionCode[1];
                }

                if (code_out & Top)
                {
                    Y = Ymax;
                    X = lX_min + (lX_max - lX_min) * (Ymax - lY_min) / (lY_max - lY_min);
                }
                else if (code_out & Bottom)
                {
                    Y = Ymin;
                    X = lX_min + (lX_max - lX_min) * (Ymin - lY_min) / (lY_max - lY_min);
                }
                else if (code_out & Right)
                {
                    Y = lY_min + (lY_max - lY_min) * (Xmax - lX_min) / (lX_max - lX_min);
                    X = lX_max;
                }
                else
                {
                    Y = lY_min + (lY_max - lY_min) * (Xmin - lX_min) / (lX_max - lX_min);
                    X = Xmin;
                }

                if (code_out == regionCode[0])
                {
                    lX_min = X;
                    lY_min = Y;
                    regionCode[0] = Compute_Code(lX_min, lY_min, Xmin, Ymin, Xmax, Ymax);
                }
                else
                {
                    lX_max = X;
                    lY_max = Y;
                    regionCode[1] = Compute_Code(lX_max, lY_max, Xmin, Ymin, Xmax, Ymax);
                }
            }
            else
            {
                cout << "\nLine Completely Outside";
                break;
            }
        }
    }
    if(accept){
        cout<<"\nLine Coordinates"<<"("<<lX_min<<","<<lY_min<<") ("<<lY_min<<","<<lY_max<<")";
    }
    else{
        cout<<"\nLine Rejected";
    }
    getch();
    closegraph();
    return 0;
}