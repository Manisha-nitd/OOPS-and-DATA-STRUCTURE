#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int det(int n, int mat[10][10])
{
    int c, subi, i, j, subj,d=0;
    int submat[10][10];
    if (n == 2)
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for(c = 0; c < n; c++)
        {
            subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + (pow(-1 ,c) * mat[0][c] * det(n - 1 ,submat));
        }
    }
    return d;
}
int main()
{
    int a[10][10],b[10][10],c[10][10];
    int r1,r2,c1,c2;
    int i,j,k,d;
    cout<<"Enter the dimension of first matrix :(Row then Column) "<<endl;
    cin>>r1>>c1;
    cout<<"Enter the dimension for second matrix :(Row then Column) "<<endl;
    cin>>r2>>c2;
    cout<<"Enter the values of first matrix :"<<endl;
    for(i=0;i<r1;i++)
    {
     for(j=0;j<c1;j++)
     {
         cin>>a[i][j];
     }
    }
    cout<<"Enter the values of second matrix :"<<endl;
    for(i=0;i<r2;i++)
    {
     for(j=0;j<c2;j++)
     {
         cin>>b[i][j];
     }
    }
    if(c1!=r2)
        cout<<"Multiplication not possible !!";
    else
    {
    for(i=0;i<r1;i++)
    {
     for(j=0;j<c2;j++)
     {
         c[i][j]=0;
        for(k=0;k<c1;k++)
        {
           c[i][j]+=(a[i][k]*b[k][j]);
        }
     }
    }
    }
     cout<<"matrix 1:"<<endl;
    for(i=0;i<r1;i++)
    {
     for(j=0;j<c1;j++)
     {
         cout<<setw(4)<<a[i][j];
     }
     cout<<endl;
    }
    cout<<"The matrix 2:"<<endl;
    for(i=0;i<r2;i++)
    {
     for(j=0;j<c2;j++)
     {
         cout<<setw(4)<<b[i][j];
     }
    cout<<endl;
    }
    cout<<"The multiplied matrix is :"<<endl;
    for(i=0;i<r1;i++)
    {
     for(j=0;j<c2;j++)
     {
         cout<<setw(4)<<c[i][j];
     }
     cout<<endl;
    }
    if(r1==c1)
    {
        d=det(r1,a);
        cout<<"The determinant of matrix1 is : "<<d<<endl;
    }
    else
        cout<<"The matrix is not a square matrix!"<<endl;
     if(r2==c2)
    {
        d=det(r2,b);
        cout<<"The determinant of matrix2 is : "<<d<<endl;
    }
    else
        cout<<"The matrix is not a square matrix!"<<endl;
   if(r1==c2)
    {
        d=det(r1,c);
        cout<<"The determinant of multiplied matrix is : "<<d<<endl;
    }
    else
        cout<<"The matrix is not a square matrix!"<<endl;
return 0;
}
