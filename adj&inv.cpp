#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
void getCofactor(int (&A)[10][10], int (&temp)[10][10], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 int determinant(int (&A)[10][10], int n)
{
    int D = 0;
    if (n == 1)
        return A[0][0];
    int temp[10][10];

    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return D;
}
void adjoint(int (&a)[10][10],int (&adj)[10][10],int n)
{
    int sign = 1, temp[10][10];
    if (n == 1)
    {
        adj[0][0] = 1;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            getCofactor(a, temp, i, j, n);

            sign = ((i+j)%2==0)? 1: -1;
            adj[j][i] = (sign)*(determinant(temp, n-1));
        }
    }
}
void inverse(int (&A)[10][10], int (&inverse)[10][10],int n)
{
    int det = determinant(A, n);
    bool res =true;
    if (det == 0)
    {
        cout << "\nSingular matrix, can't find its inverse!!\n";
        res=false;
    }
    int adj[10][10];
    adjoint(A, adj,n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            inverse[i][j] = adj[i][j]/float(det);
    }
    if(res)
    {
       cout<<"THE INVERSE OF THE MATRIX IS :\n";
       for(int i=0;i<n;i++)
        {
         for(int j=0;j<n;j++)
           cout<<"  "<<inverse[i][j];
        cout<<endl;
        }
    }
}
int main()
{
    int n;
    int a[10][10];
    cout<<"        :PROGRAM TO CALCULATE ADJOINT AND INVERSE OF A MATRIX :\n";
    cout<<"\n\nEnter the matrix diension:"<<endl;
    cin>>n;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<n;i++)
    {
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
    int adj[10][10],inv[10][10];
    cout<<"\n\n          :THE MATRIX OPERATIONS ARE :\n";
    while(1)
    {
        cout<<"\n1.FIND ADJOINT\n2.FIND INVERSE\n3.EXIT\n";
        int o;
        bool res;
        cin>>o;
        switch(o)
        {
        case 1:
            adjoint(a,adj,n);
            cout<<"THE ADJOINT OF THE MATRIX IS :\n";
             for(int i=0;i<n;i++)
             {
                for(int j=0;j<n;j++)
                    cout<<"  "<<adj[i][j];
                cout<<endl;
            }
            break;
        case 2:
            inverse(a,inv,n);
            break;
        case 3:
            exit(1);
        default:
            cout<<"INVALID INPUT!!!"<<endl;
        }
    }
    return 0;
}

