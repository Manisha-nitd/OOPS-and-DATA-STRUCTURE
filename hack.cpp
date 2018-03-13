#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int l,v1,v2,Q,i;
    cin>>l>>v1>>v2;
    cin>>Q;
    long double *q=new long double[Q];
    for(i=0;i<Q;i++)
        {
        cin>>q[i];
    }
    for(i=0;i<Q;i++)
        {
        unsigned long double t;
       unsigned long double side,dig,dis;
        int rv= abs(v1-v2);
        side= sqrt(q[i]);
        dig=sqrt(2)*side;
        dis=sqrt(2)*l-dig;
        t=dis/rv;
        cout<<t<<endl;
    }
    return 0;
}
