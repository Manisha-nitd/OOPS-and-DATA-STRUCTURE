#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,num;
    vector<int> v;
    cout<<"                     :VECTOR SORT:\n\n";
    cout<<"Enter the number of elements of vector:";
    cin>>n;
    cout<<"\nEnter the elements of the vector:";
    while(n--)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout<<"\n\nThe sorted vector is :";
    vector<int>::iterator i=v.begin();
    while(i!=v.end())
    {
        cout<<" "<<*i;
        i++;
    }
    return 0;
}
