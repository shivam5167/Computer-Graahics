#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float x1,y1,x2,y2;
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
    float p=2*dy-dx;
    cout<<"All the middle points are: "<<endl;
    cout<<"("<<x1<<","<<y1<<")"<<endl;
    if(m<1)
    {
        while(x1!=x2){
          if(p<0)
          {
            x1=x1+1;
            y1=y1;
            p=p+2*dy;
            cout<<"("<<round(x1)<<","<<round(y1)<<")"<<endl;
          }
          else
          {
            x1=x1+1;
            y1=y1+1;
            p=p+2*dy-2*dx;
            cout<<"("<<round(x1)<<","<<round(y1)<<")"<<endl;
          }
        }
    }
    else
    {
        while(y1!=y2){
          if(p<0)
          {
            x1=x1;
            y1=y1+1;
            p=p+2*dx;
            cout<<"("<<round(x1)<<","<<round(y1)<<")"<<endl;
          }
          else
          {
            x1=x1+1;
            y1=y1+1;
            p=p+2*dx-dy;
            cout<<"("<<round(x1)<<","<<round(y1)<<")"<<endl;
          }
        }
    }
    return 0;
}
