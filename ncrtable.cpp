#include<iostream>
#include<iomanip>
using namespace std;
long int fact(int n)
{
    int f;
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int m,i,r,n,ncr;
    cout<<"Enter the number of rows :"<<endl;
    cin>>m;
    cout<<"      ";
    for(i=0;i<m;i++)
    {
      cout<<setw(3)<<i+1<<setw(3)<<'|';
    }
    cout<<endl<<endl;
     for(r=1;r<=m;r++)
    {
      cout<<setw(3)<<r<<setw(3)<<'|';
      for(n=1;n<=m;n++)
      {
       if(r>n)
        cout<<setw(3)<<'-'<<setw(3)<<'|';
       else{
         ncr=fact(n)/(fact(r)*fact(n-r));
        cout<<setw(3)<<ncr<<setw(3)<<'|';
      }
      }
      cout<<endl<<endl;
    }
 return 0;
    }

