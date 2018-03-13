#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    cout<<"\t\t\tRANDOM\n";
    double x,y,v=1;
    srand(time(NULL));
    do
    {

    cout<<"Enter the range for generating a random number (initial-final) :\n";
    cin>>x>>y;
    while(v<x || v>y)
    {
         v=static_cast<double>(rand())/static_cast<double>(y);
    }

    cout<<"Random Number: "<<v<<endl;

    cout<<" Press y/Y to continue :\n";
    cin>>ch;
    }
    while(ch=='y'|| ch=='Y');
}
