#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int sum=0,max=INT_MIN;
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int k=0,mid=0;
    for(int i=0;i<4;i++)
        {
        sum=0,mid=arr[i+1][k+1];
        for(int j=k;j<3;j++)
            {
            sum=sum+arr[i][j]+arr[i+2][j];
        }
         k++;
         sum=sum+mid;
         if(sum>max)
             max=sum;
    }
    cout<<max;
    return 0;
}

