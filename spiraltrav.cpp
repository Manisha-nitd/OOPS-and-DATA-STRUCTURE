#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int row,column;
    int **a;
    a=new int*[row];
    cout<<"\n         SPIRAL TRAVERSAL OF A MATRIX \n";
    cout<<"Enter the matrix diension(row then column) :"<<endl;
    cin>>row>>column;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<row;i++)
    {
        *(a+i)=new int[column];
        for(int j=0;j<column;j++)
            cin>>a[i][j];
    }
    cout<<"Displaying the matrix :\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
    int rb,re,cb,ce;
    rb=0;
    cb=0;
    re=row;
    ce=column;
    cout<<"The spiral traversal of matrix :";
    while(rb<re && cb<ce)
    {
        if(cb<ce)
        {
        for(int i=cb;i<ce;i++)
            cout<<setw(2)<<a[rb][i];
        rb++;
        }
        if(rb<re)
        {
        for(int j=rb;j<re;j++)
            cout<<setw(2)<<a[j][ce-1];
        ce--;
        }
        if(rb<re)
        {
            for(int i=ce-1;i>=cb;i--)
               cout<<setw(2)<<a[re-1][i];
            re--;
        }
        if(cb<ce)
        {
             for(int j=re-1;j>=rb;j--)
                cout<<setw(2)<<a[j][cb];
            cb++;
        }

    }
return 0;
}
