#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream myfile;
    myfile.open("syslog");
    string line,s1="kernel",check;
    while(getline(myfile,line))
    {
        for(int i=23;i<29;i++)
            check=check+line[i];
        if(s1.compare(check)==0)
        {
            cout<<line;
            cout<<endl;
            check.clear();
        }
    }

}
