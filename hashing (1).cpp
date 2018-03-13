#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int *a;
int size,m,key;
cout<<"Enter the size of the hash table(atleast 10):";
cin>>size;
a=new int[size];
for(int i=0;i<size;i++)
{
   a[i]=-1;
}
cout<<"Enter the number of key values :";
cin>>m;
for(int j=0;j<m;j++)
   {
     cout<<"Enter the key value :";
     cin>>key;
     int t=key%10;
     while(t<size && t)
          {
           if(a[t]==-1)
             {
              a[t]=key;
              t=0;
              }
          else
              t++;
           }
     }
cout<<"\nThe hash table is :"<<endl;
for(int i=0;i<size;i++)
{
cout<<setw(4)<<a[i];
}
return 0;
}
