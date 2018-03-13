#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;
class String
{
    char str[20];
    public:
    void getdata()
    {
        gets(str);
    }
    int operator ==(String s)
    {
        if (!strcmp(str,s.str))
        {
            return 1;
        }
        else
            return 0;
    }
};
int main()
{
    String s1,s2;
    cout<<"              :STRING COMPARISON USING OPERATOR OVERLODING:\n\n";
    cout<<"Enter 1st string :"<<endl;
    s1.getdata();
    cout<<"Enter 2nd string :"<<endl;
    s2.getdata();
    if (s1==s2)
        cout<<"Strings are EQUAL";
    else
        cout<<"Strings are NOT EQUAL";
    return 0;

}
