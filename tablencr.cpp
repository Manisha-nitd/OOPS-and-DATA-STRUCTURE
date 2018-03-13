#include<iostream>
#include<iomanip>
int fact(int n,int r)
{
    int f;
    if(r==0)
        return 1;
    if(n==r && r!=0 )
        return r;
    else
        f=n*fact(n-1,r);
        return f;
}
float comb(int n,int r)
{
    int a,b;
    a=fact(n,r+1);
    b=fact(n-r,0);
    return float(a/b);
}
int main()
{
    int n,r,k;
    float ncr;
    using namespace std;
    cout<<"Enter value of n :"<<endl;
    cin>>n;
    for(k=0;k<=n;k++)
{
    cout<<n;
    cout<<" "<<k;
    ncr= comb(n,k);
    cout<<ncr;
}
return 0;
}
