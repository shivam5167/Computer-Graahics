#include <stdio.h>
#include <stdlib.h>
//#include <graphics.h>
#include <math.h>
#include<conio.h>
#include<iostream>
using namespace std;
void bezier (int x[4], int y[4])
{
//    int gd = DETECT, gm;
    int i;
    double t;
 
//    initgraph (&gd, &gm, "..\\bgi");
 
    for (t = 0.0; t < 1.0; t += 0.1)
    {
	double xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] +
		    3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];
 
	double yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] +
		    3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];
 
//	putpixel (xt, yt, WHITE);
cout<<xt<<" "<<yt<<endl;
    }
 
//    for (i=0; i<4; i++)
//	putpixel (x[i], y[i], YELLOW);
}
 
int main()
{
    int x[4], y[4];
    int i;
 
    printf ("Enter the x- and y-coordinates of the four control points.\n");
    for (i=0; i<4; i++)
	cin>>x[i]>>y[i];
 
    bezier (x, y);
    cout<<"end";
    return 0;
}
