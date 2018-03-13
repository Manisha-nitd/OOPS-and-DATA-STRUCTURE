#include<iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
int n,j=0;
string s,ans;
cin>>n;
while(n--)
{
cin>>s;
int i=s.length()-1;
while(s[i]!=' '&& i!=-1)
{
ans[j++]='m';
//cout<<tolower('s[i]');
cout<<ans[j];
i--;
}
ans[--j]=toupper(s[++i]);
j++;
i=i-2;
while(i>=-1)
{
if(s[i]==' '||s[i]==-1)
{
ans[j++]=' ';
ans[j++]='.';
ans[j++]=toupper(s[++i]);
i=i-2;
continue;
}
i--;
}
/*for(int i=ans.length();i>0;i--)
{
    cout<<ans[i];
}*/
cout<<ans<<endl;
}
}
