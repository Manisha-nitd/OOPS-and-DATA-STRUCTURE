#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,sum=0;
    int **a;
    a=new int*[n];
    cout<<"Enter the matrix diension(square matrix):"<<endl;
    cin>>n;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<n;i++)
    {
        *(a+i)=new int[n];
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
     cout<<"\n\nDisplaying the matrix :"<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
    cout<<"\n\n          :THE MATRIX OPERATIONS ARE :\n";
    while(1)
    {
        cout<<"\n1.CALCULATE TRACE\n2.CALCULATE NORMAL\n3.EXIT\n";
        int o;
        cin>>o;
        switch(o)
        {
        case 1:
            sum=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                        sum=sum+a[i][j];
                }
            }
            cout<<"The TRACE of the matrix is :"<<sum<<endl;
            break;
        case 2:
            sum=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                 sum=sum+a[i][j];
                }
            }
            float normal;
            normal=sqrt(sum);
            cout<<"The NORMAL of the matrix is :"<<normal<<endl;
            break;
        case 3:
            exit(1);
        default:
            cout<<"INVALID INPUT!!!"<<endl;
        }
    }
    return 0;
}
