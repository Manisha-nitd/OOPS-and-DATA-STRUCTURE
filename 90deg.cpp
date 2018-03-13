#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int row,column;
    int **a;
    int count=0,max=0,flag=0;
    a=new int*[row];
    cout<<"                :PROGRAM TO ROTATE A MATRIX BY 90 DEGREE(CLOCKWISE) :";
    cout<<"\n\nEnter the matrix diension(row then column) :"<<endl;
    cin>>row>>column;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<row;i++)
    {
        *(a+i)=new int[column];
        for(int j=0;j<column;j++)
            cin>>a[i][j];
    }
    cout<<"\n\nDisplaying the original matrix :"<<endl;
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
    int **b;
    b=new int*[column];
    for(int i=0;i<column;i++)
    {
     *(b+i)=new int[row];
     for(int j=0;j<row;j++)
     {
         b[i][j]=a[row-1-j][i];
     }
    }
    cout<<"\n\nDisplaying the rotated matrix :"<<endl;
     for(int i=0;i<column;i++)
    {
        for(int j=0;j<row;j++)
            cout<<" "<<b[i][j];
        cout<<endl;
    }
return 0;
}
