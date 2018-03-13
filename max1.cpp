#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int row,column;
    int **a,*b;
    int count=0,max=0,flag=0;
    a=new int*[row];
    b=new int[row];
    cout<<"                :PROGRAM TO CHECK ROW FOR MAXIMUM NUMBER OF 1'S :";
    cout<<"\n\nEnter the matrix diension(row then column) :"<<endl;
    cin>>row>>column;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<row;i++)
    {
        *(a+i)=new int[column];
        for(int j=0;j<column;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<row;i++)
    {
        count=0;
        for(int j=0;j<column;j++)
        {
            if(a[i][j]==1)
            {
              count++;
              flag=1;
            }
        }
        b[i]=count;//to store the number of 1's in each row.
        if(count>max)
             max=count;
    }
    cout<<"\n\nDisplaying the matrix :"<<endl;
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
    if(flag)
    {
        cout<<"\nThe maximum number of 1 is in the row :";
        for(int i=0;i<row;i++)
        {
            if(b[i]==max)//more than one row may have maximum number of 1's.
               cout<<"  "<<i+1;
        }
    }
    else
        cout<<"\n\nNO '1's are present !!"<<endl;
    return 0;
}
