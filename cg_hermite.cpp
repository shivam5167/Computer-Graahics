#include<iostream>
//#include<graphics.h>
#include<conio.h>
using namespace std;
 
struct point
{
int x,y;
};
 
void hermite(point p1,point p4,point r1,point r4)
{
	float x,y,t;
	for(t=0.0;t<=1.0;t+=.1)
	{
		x=(2*t*t*t-3*t*t+1)*p1.x+(-2*t*t*t+3*t*t)*p4.x+(t*t*t-2*t*t+t)*r1.x+(t*t*t-t*t)*r4.x;
		y=(2*t*t*t-3*t*t+1)*p1.y+(-2*t*t*t+3*t*t)*p4.y+(t*t*t-2*t*t+1)*r1.y+(t*t*t-t*t)*r4.y;
//		putpixel(x,y,YELLOW);
		cout<<x<<" "<<y<<endl;
	 }
}
 
int main()
{
//	int gd=DETECT,gm;
//	double r1,r4;
//	initgraph(&gd,&gm,"..//BGI");
	point p1,p4,r1,r4;
	cout<<"Enter 2 hermite points:\n";
	cin>>p1.x;
	cin>>p1.y;
	cin>>p4.x;
	cin>>p4.y;
	cout<<"Enter the tangents at p1,p4";
	cin>>r1.x>>r1.y;
	cin>>r4.x>>r4.y;
//	cleardevice();
	hermite(p1,p4,r1,r4);
      //	putpixel(x1,y1,WHITE);
	//putpixel(x2,y2,WHITE);
	cout<<"end";
	getch();
//	closegraph();
	return 0;
}
