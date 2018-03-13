#include<iostream>
#include<iomanip>
 #include<cmath>
using namespace std;
int main()
{
  int a1,a2,sw;
  double x,y,u,v,i,j;
  cout<<" Enter the lower angle(in degree) :"<<endl;
  cin>>a1;
  cout<<"Enter the upper angle(in degree):"<<endl;
  cin>>a2;
  cout<<"Enter the stepwidth :"<<endl;
  cin>>sw;
  for(i=a1;i<=a2;i=i+sw)
  {
      x=double(sin(double(i*3.14/180)));
      if(x>0)
      {
          cout<<setw(40)<<'|';
          y=x*30;
          for(j=1;j<=y;j++)
          {
              cout<<'-';
          }
          cout<<'*';
      }
      else if(x<0)
      {
          u=abs(x)*30;
          v=40-u;
          cout<<setw(v)<<'*';
          for(j=1;j<=u;j++)
            cout<<'-';
          cout<<'|';
      }
    else
    {
        cout<<setw(40)<<'|';
    }
  cout<<endl;
  }
  return 0;
}
