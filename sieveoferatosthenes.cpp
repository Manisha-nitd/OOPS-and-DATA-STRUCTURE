#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cout<<"Enter the number:";
    int n;
    cin>>n;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    //prime is the pointer to the object to fill
    //true is the value that is to be filled
    //sizeof defines number of bytes to fill.
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int j=2*i;j<=n;j+=i)
                prime[j]=false;
        }
    }
    cout<<"The prime numbers below"<<n<<"is :";
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
            cout<<i<<" ";
    }
}
