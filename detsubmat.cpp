#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int det(int n,int row,int column,int a[10][10])
{
    int c, subi, i, j, subj,d=0;
    int submat[10][10];
    if (n == 2)
    {
        return( (a[row][column] * a[row+1][column+1]) - (a[row+1][column] * a[row][column+1]));
    }
    else
    {
        for(c = column; c < n; c++)
        {
            subi = 0;
            for(i = row+1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = a[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + (pow(-1 ,c) * a[row][c] * det(n - 1 ,0,0,submat));
        }
    }
    return d;
}
int main()
{
   int row,column;
    int a[10][10];
    cout<<"\n\nEnter the matrix dimension(row then column):"<<endl;
    cin>>row>>column;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"\n\nDisplaying the matrix :"<<endl;
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
     cout<<"                :DETERMINANT OF SUBMATRIX:         \n";
     int r1,r2,c1,c2;
     int d;
     char c='y';
     while(c=='y'||c=='Y')
     {
     cout<<"\nEnter the row number of submatrix (initial then final):"<<endl;//row number starting from 1.
     cin>>r1>>r2;
     cout<<"\nEnter the column number of submatrix (initial then final):"<<endl;//column number starting from 1.
     cin>>c1>>c2;
     if((r2-r1)!=(c2-c1))
     {
        cout<<"\nDETERMINANT NOT POSSIBLE! SUBMATRIX IS NOT SQUARE MATRIX!TRY AGAIN!\n";
        continue;
     }
     if(r1>row || r2>row || c1>column || c2> column)
     {
         cout<<"\n INVALID INPUT! TRY AGAIN!!\n";
         continue;
     }
     else
        {
        d=det(r2-r1+1,r1-1,c1-1,a);
        cout<<"DETERMINANT IS :"<<d;
        }
     cout<<"\n\nWant to continue ?? Press y/Y"<<endl;
     cin>>c;
     }
return 0;
}

