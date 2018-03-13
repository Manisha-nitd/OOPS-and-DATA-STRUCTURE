#include<iostream>
#include<iomanip>
int main()
{
    using namespace std;
    int n,i,k,j;
    cout<<"Enter the height of the triangle :"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
       cout<<setw(n-i+1)<<setfill(' ');
       k=1;
       while(k<=(2*i-1))
       {
          if(k<=i)
          {
            cout<<" "<<k++;
            j=k;
          }
          else
          {
            cout<<" "<<j-2;
            k++;j--;
          }
       }
       cout<<endl;
    }
}
