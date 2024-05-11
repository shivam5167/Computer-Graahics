// 2D transformations 
#include<graphics.h>
#include <conio.h>
#include<math.h>
#include<iostream>

using namespace std;

class Point
{
	public:
		int x,y;
};

double** convert(Point *p, int n)
{
	double **X = NULL;
	X = new double*[n];
	
	for(int i = 0; i < n; ++i)
	{
		X[i] = new double[3];
	}
	
	for(int i = 0; i < n; ++i)
	{
		X[i][0] = p[i].x;
		X[i][1] = p[i].y;
		X[i][2] = 1;
	}
	
	return X;
}

void drawLine(double x0, double y0, double x1, double y1)
{
	int max_x = getmaxx();
	int max_y = getmaxy();
	int max_x_2 = max_x / 2;
	int max_y_2 = max_y / 2;
	
	x0 = max_x_2 + x0;
	x1 = max_x_2 + x1;
	y0 = max_y_2 - y0;
	y1 = max_y_2 - y1;
	
	line(x0,y0,x1,y1);	
}

void drawFigure(double **X, int n)
{
	//cout<<"\nIn drawFigure()\n";
	for(int i = 0; i < n-1; ++i)
	{
		drawLine(X[i][0], X[i][1], X[i+1][0], X[i+1][1]);
	}
	drawLine(X[n-1][0], X[n-1][1], X[0][0], X[0][1]);
}

void drawGraph(double **X, int n)
{
	//cout<<"\nIn drawGraph()\n";
	int max_x = getmaxx();
	int max_y = getmaxy();
	int max_x_2 = max_x / 2;
	int max_y_2 = max_y / 2;
	
	line(max_x_2,0,max_x_2,max_y);
	line(0,max_y_2,max_x,max_y_2);
	
	drawFigure(X,n);
	
	setcolor(RED);
}

double** multiplyMatrices(double **X, double T[3][3], int n)
{
	int i, j, k;
	double **newPoints = NULL;
	newPoints = new double*[n];
	
	for(int i = 0; i < n; ++i)
	{
		newPoints[i] = new double[3];
	}

	for(i = 0; i < n; ++i)
		for(j = 0; j < 3; ++j)
			newPoints[i][j] = 0;

	for(i = 0; i < n; ++i)
		for(j = 0; j < 3; ++j)
			for(k=0; k < 3; ++k)
				newPoints[i][j] += X[i][k] * T[k][j];
	
	return newPoints;
}

void reflection(double **X, int n)
{
	int ch;
	cout<<"\nReflection about the line ?\n"
		<<"1. y = 0 (x-axis)\n"
		<<"2. x = 0 (y-axis)\n"
		<<"3. y = x\n"
		<<"4. y = -x\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	
	double T[3][3] = {{0,0,0}, {0,0,0}, {0,0,1}};
	switch(ch)
	{
		case 1: {
			T[0][0] = 1;
			T[1][1] = -1;
			break;
		}
				
		case 2: {
			T[0][0] = -1;
			T[1][1] = 1;
			break;
		}
		
		case 3: {
			T[0][1] = 1;
			T[1][0] = 1;
			break;
		}
				
		case 4: {
			T[0][1] = -1;
			T[1][0] = -1;
			break;
		}
		
		default: cout<<"\nInvalid choice! Please choose a valid option!\n";
	}

	double **newPoints = multiplyMatrices(X, T, n);
	drawFigure(newPoints, n);
	setcolor(WHITE);
}

void rotation(double **X, int np)
{
	double m,n,angle;
	cout<<"\nRotation about the point ?\n";
	cout<<"x = "; cin>>m;
	cout<<"y = "; cin>>n;
	cout<<"Angle of Rotation (in degrees): ";
	cin>>angle;
	//converting in radians
	double theta = angle * 3.14 / 180;
	double cos_t = cos(theta);
	double sin_t = sin(theta);
	double term_2_0 = (-m)*(cos_t-1) + n*sin_t;
	double term_2_1 = (-n)*(cos_t-1) - m*sin_t;
	
	double T[3][3] = { 
		{cos_t, sin_t, 0},
		{-sin_t, cos_t, 0},
		{term_2_0, term_2_1, 1}
	};
//	cout<<"\nMatrix T : \n";
//	for(int i = 0; i < 3; ++i)
//	{
//		cout<<endl;
//		cout<<T[i][0]<<"  "<<T[i][1]<<"  "<<T[i][2];
//	}
	
	double **newPoints = multiplyMatrices(X, T, np);
//	cout<<"\nNew Points : \n";
//	for(int i = 0; i < 3; ++i)
//	{
//		cout<<endl;
//		cout<<newPoints[i][0]<<"  "<<newPoints[i][1]<<"  "<<newPoints[i][2];
//	}

	drawFigure(newPoints, np);
	setcolor(WHITE);	
}

void scaling(double **X, int n)
{
	double sx, sy;
	cout<<"\nScaling factor for x : ";
	cin>>sx;
	cout<<"\nScaling factor for y : ";
	cin>>sy;
	
	double T[3][3] = {{sx,0,0}, {0,sy,0}, {0,0,1}};
	
	double **newPoints = multiplyMatrices(X, T, n);
	
	drawFigure(newPoints, n);
	setcolor(WHITE);
}

void translation(double **X, int n)
{
	double tx, ty;
	cout<<"\nTranslating factor in x-direction : ";
	cin>>tx;
	cout<<"\nTranslating factor in y-direction : ";
	cin>>ty;
	
	double T[3][3] = {{1,0,0}, {0,1,0}, {tx,ty,1}};
	
	double **newPoints = multiplyMatrices(X, T, n);
	
	drawFigure(newPoints, n);
	setcolor(WHITE);	
}

int main()
{
	int n;
	cout<<"Enter no. of points (>= 2): ";
	cin>>n;
	
	Point *p = new Point[n];
	cout<<"Enter the points : ";
	for(int i = 0; i < n; ++i)
	{
		cout<<endl;
		cout<<"x"<<i+1<<": ";
		cin>>p[i].x;
		cout<<"y"<<i+1<<": ";
		cin>>p[i].y;
	}
	
	cout<<"Converting to homogeneous coordinates...\n";
	double **hom_p = convert(p,n);
	
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	
	int ch = 0;
	do
	{
		cout<<"\nMenu : \n"
			<<"1. Reflection\n"
			<<"2. Rotation\n"
			<<"3. Scaling\n"
			<<"4. Translation\n"
			<<"5. Exit\n";
		cout<<"Enter your choice (1/2/3/4/5): ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: cleardevice();
					drawGraph(hom_p,n);
					reflection(hom_p,n);
					break;
					
			case 2: cleardevice();
					drawGraph(hom_p,n);
					rotation(hom_p,n);
					break;	
					
			case 3: cleardevice();
					drawGraph(hom_p,n);
					scaling(hom_p,n);
					break;
					
			case 4: cleardevice();
					drawGraph(hom_p,n);
					translation(hom_p,n);
					break;
			case 5: return 0;
			default: cout<<"\nInvalid choice! Please choose a valid option!\n";
		}
	}while(ch != 5);
	
	getch();
	closegraph();
	return 0;
}
