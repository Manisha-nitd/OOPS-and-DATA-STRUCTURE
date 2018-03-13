#include<iostream>
using namespace std;
int main()
{
    int n,sum=0;
    int **a;
    int flag1=1,flag2=1;
    a=new int*[n];
    cout<<"                      :TRIANGULAR MATRICES:         ";
    cout<<"\n\nEnter the matrix dimension(square):"<<endl;
    cin>>n;
    cout<<"Enter the matrix value:"<<endl;
    for(int i=0;i<n;i++)
    {
        *(a+i)=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            sum=sum+a[i][j];
        }
    }
    cout<<"\n\nDisplaying the matrix :"<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
 for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                if(a[i][j]!=0)
                    flag1=0;
            }
            else if(i>j)
            {
                if(a[i][j]!=0)
                    flag2=0;
            }
            else
            {
                if(a[i][j]==0)
                {
                flag1=0;
                flag2=0;
                }
            }
        }
    }
        if(flag1 || flag2)
        {
            if(flag1&& !flag2)
            {
               cout<<"\n THE MATRIX IS A LOWER TRIANGULAR MATRIX !\n";
               cout<<"\nThe sum is :"<<sum;
            }
            else if(!flag1 && flag2)
            {
                 cout<<"\n THE MATRIX IS A UPPER TRIANGULAR MATRIX!\n";
                 cout<<"\nThe sum is :"<<sum;
            }
            else
                cout<<"\nTHIS IS A DIAGONAL MATRIX !!\n";
        }
        else
            cout<<"\nTHIS IS NOT A TRIANGULAR MATRIX!";
    return 0;
}


