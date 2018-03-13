#include<iostream>
#include<iomanip>
long int fact(int n)
{
    int f;
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    int m,r,i,j;
    float ncr;
    using namespace std;
    cout<<"Enter value of m :"<<endl;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i>j)
                cout<<"-"<<" ";
            else
                {
            ncr=fact(j)/(fact(i)*fact(j-i));
            cout<<ncr;
        }
        }
        cout<<endl;
}
}

