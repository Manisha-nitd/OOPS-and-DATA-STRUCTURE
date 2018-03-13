#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,column,temp,flag=0;
    int **a;
    a=new int*[row];
    cout<<"\n\nEnter the matrix dimension:(Row then Column)"<<endl;
    cin>>row>>column;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<row;i++)
    {
        *(a+i)=new int[column];
        for(int j=0;j<column;j++)
            cin>>a[i][j];
    }
    cout<<"\n\nDisplaying the matrix :"<<endl;
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }


    cout<<"\n\n          :THE MATRIX OPERATIONS ARE :\n";
    while(1)
    {
        cout<<"\n1.INTERCHANGE ROWS\n2.INTERCHANGE COLUMN\n3.EXIT\n";
        int o;
        cin>>o;
        switch(o)
        {
        case 1:
             int r1,r2;
             flag=0;
            cout<<"Enter the row number you want to exchnage (first then next) :"<<endl;
            cin>>r1>>r2;
            if(r1<=row && r2<=row)
            {
                flag=1;
                for(int j=0;j<column;j++)
                {
                    temp=a[r1-1][j];
                    a[r1-1][j]=a[r2-1][j];
                    a[r2-1][j]=temp;
                }
            }
            else
                cout<<"INVALID INPUT!!"<<endl;
            if(flag)
            {
            cout<<"The new array is :"<<endl;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                    cout<<setw(3)<<a[i][j];
                cout<<endl;
            }
            }
            break;
        case 2:
             int c1,c2;
             flag=0;
            cout<<"Enter the column number you want to exchnage (first then next) :"<<endl;
            cin>>c1>>c2;
            if(c1<=column && c2<=column)
            {
                flag=1;
                for(int i=0;i<row;i++)
                {
                    temp=a[i][c1-1];
                    a[i][c1-1]=a[i][c2-1];
                    a[i][c2-1]=temp;
                }
            }
            else
                cout<<"INVALID INPUT!!"<<endl;
            if(flag)
            {
            cout<<"The new array is :"<<endl;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                    cout<<setw(3)<<a[i][j];
            cout<<endl;
            }
            }
            break;
        case 3:
            exit(1);
        default:
            cout<<"INVALID INPUT!!!"<<endl;
        }
    }
    return 0;
}


