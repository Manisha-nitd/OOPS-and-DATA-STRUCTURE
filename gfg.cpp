#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <int> v1,v2;
    int g,count=0;
    cin>>g;
    for(int i=0;i<g;i++)
    {
        long int n1,n2,sum=0;
        long long int x;
        cin>>n1>>n2>>x;
        int num;
        for(int j=0;j<n1;j++)
        {
            cin>>num;
            v1.push_back(num);
        }
        for(int j=0;j<n2;j++)
        {
            cin>>num;
            v2.push_back(num);
        }
        while(!v1.empty() && !v2.empty())
        {
        if(v1.front()<v2.front()  && sum+v1.front()<=x)
        {
            sum+=v1.front();
            v1.erase(v1.begin());
            count++;
        }
        else if(v2.front()<v1.front()  && sum+v2.front()<=x)
        {
            sum+=v2.front();
            v2.erase(v2.begin());
            count++;
        }
        }
            while(!v2.empty() && sum<=x)
            {
                sum+=v2.front();
                v2.erase(v2.begin());
                count++;

            }
            while(!v2.empty() && sum<=x)
            {
                sum+=v2.front();
                v2.erase(v2.begin());
                count++;
            }
        cout<<count<<endl;
    }

    return 0;
}
