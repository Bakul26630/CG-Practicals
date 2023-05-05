// Mid-Point Circle Drawing Algorithm
#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

void pixel(float x, float y,int c)
{

    putpixel(x+c, y+c, WHITE);
    putpixel(y+c, x+c, WHITE);
    putpixel(-x+c, y+c, WHITE);
    putpixel(-y+c, x+c, WHITE);
    putpixel(x+c, -y+c, WHITE);
    putpixel(y+c, -x+c, WHITE);
    putpixel(-x+c, -y+c, WHITE);
    putpixel(-y+c, -x+c, WHITE);
    return;
}


int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    int radius;
    int center;

    cout<<"Enter Radius of circle: ";
    cin>>radius;

    cout<<"Enter Center Coordinate: ";
    cin>>center;

    float d=1.25-radius;
    float x=0;
    float y=radius;
    while(y>=x){
        pixel(x,y,center);
        if(d<0){
            d+=2*x+3;
            x++;
        }
        else{
            d+=2*(x-y)+5;
            x++;
            y--;
        }
    }

    getch();
    closegraph();
    return 0;
}