#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");
    string s;
    int flag=0;
    int x=0;
    while(getline(infile,s))
    {
        if(s[0]=='}')
        {
            flag=0;
            x--;
        }
        if(flag==0||x>0)
        {
            for(int i=0;i<=x;i++)
                outfile<<" ";
        }
        outfile<<s<<endl;
        if(s[0]=='{')
            {
                flag=1;
                x++;
            }
    }
    return 0;
}
