#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float x1,y1;
    float r;
    cout<<"Enter the value of r: ";
    cin>>r;
    float p;
    x1=0;
    y1=r;
    cout<<"All the points are: "<<endl;
    p=1-r;
    do
    {   
        cout<<"("<<round(x1)<<","<<round(y1)<<")"<<"  "<<"("<<round(-x1)<<","<<round(y1)<<")"<<"  "<<"("<<round(-x1)<<","<<round(-y1)<<")"<<"  "<<"("<<round(x1)<<","<<round(-y1)<<")"<<endl;
        cout<<"("<<round(y1)<<","<<round(x1)<<")"<<"  "<<"("<<round(-y1)<<","<<round(x1)<<")"<<"  "<<"("<<round(-y1)<<","<<round(-x1)<<")"<<"  "<<"("<<round(y1)<<","<<round(-x1)<<")"<<endl;
        if(p<0)
        {
            x1=x1+1;
            y1=y1;
            p=p+2*x1+1;
        }
        else
        {
            x1=x1+1;
            y1=y1-1;
            p=p+2*(x1-y1)+5;
        }
    }while(x1<y1);
return 0;
}    
