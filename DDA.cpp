#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float x1,y1,x2,y2;
    int p,q;
    cout<<"Enter the value of x1: ";
    cin>>x1;
    cout<<"Enter the value of y1: ";
    cin>>y1;
    cout<<"Enter the value of x2: ";
    cin>>x2;
    cout<<"Enter the value of y2: ";
    cin>>y2;
    float dx=x2-x1;
    float dy=y2-y1;
    float m=dy/dx;
    cout<<"All the middle points are: "<<endl;
    cout<<"("<<x1<<","<<y1<<")"<<endl;
    if(abs(dx)>=abs(dy))
    {

        while(x1!=x2)
        {
            x1=x1+1;
            y1=y1+m;
            cout<<"("<<round(x1)<<","<<round(y1)<<")"<<endl;
        }
    }
    else
    {
        while(y1!=y2)
        {
            x1=x1+1/m;
            y1=y1+1;
            cout<<"("<<round(x1)<<","<<round(y1)<<")"<<endl;
        }
    }
    return 0;
}
