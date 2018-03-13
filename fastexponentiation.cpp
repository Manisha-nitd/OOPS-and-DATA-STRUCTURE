#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter base,power and modulus respectively :";
    int base,power,mod;
    cin>>base>>power>>mod;
    int result=1;
    while(power>0)
    {
        if(power&1)
        {
            result=(result*base)%mod;
        }
       power=power>>1;//divides y by 2 BY BITWISE SHIFTING.
       base=(base*base)%mod;
    }
    cout<<"The result is :"<<result;
}
