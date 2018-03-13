#include<iostream>
#include<iomanip>
int main()
{
using namespace std;
int a,i,k,j;
  cout<<"Enter the amplitude of wave :"<<endl;
  cin>>a;
  for(i=1;i<=2*a;i++)
  {
      cout<<setw(a+1)<<'|';
      if(i<=a)
      {
      for(k=1;k<=i;k++)
      {
          cout<<'*';
      }
      }
      else{
      for(j=k-1;j>0;j--)
      {
          cout<<'*';
      }
      k--;
      }
     cout<<endl;
  }
  for(i=1;i<=2*a;i++)
  {
      if(i<=a)
      {
       cout<<setw(a+1-i);
      for(k=a-i;k<a;k++)
      {
          cout<<'*';
      }
      }
      else{
        cout<<setw(i-a+1);
      for(j=k-1;j>0;j--)
      {
          cout<<'*';
      }
      k--;
      }
      cout<<'|';
     cout<<endl;
  }

}
