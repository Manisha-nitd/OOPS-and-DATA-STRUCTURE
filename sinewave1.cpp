#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
    int a1,a2,sw;
    float y1,y2,i;
   long double x1,x2;
    cout<<"Enter the initial angle :(in degree)";
    cin>>a1;
    cout<<"Enter the final angle :(in degree)";
    cin>>a2;
    cout<<"Enter the step width :";
    cin>>sw;
    y1=(a1*3.14)/180;
    y2=(a2*3.14)/180;
    x1=sin(y1);
    x2=sin(y2);
    for(i=x1;i<x2&&i>0;i=1+0.5)
    {
        cout<<setw(50)<<'|'<<setw(x1*50)<<setfill('*')<<endl;
    }
}
