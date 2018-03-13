#include<bits/stdc++.h>
using namespace std;
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
    vector<int> v;
    stringstream ss(str);
    char ch;
    int n;
    int len=str.length();
    len=ceil(len/2);
    cout<<len<<endl;
    while(len--)
    {
    ss>>n;
     v.push_back(n);
        ss>>ch;
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
