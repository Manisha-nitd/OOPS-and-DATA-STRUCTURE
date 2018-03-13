#include "bits/stdc++.h"
using namespace std;

int main()
{
  ifstream myfile,myfile1;
  int c=0,c1=0,flag;
myfile.open("syslog");
  string line,s1="kernel";

  while(getline(myfile,line))
 {
     c++;
     string check;
     for(int i=0;i<line.size();i++)
     {
        if(i+6<line.size())
        {
		      for(int j=i;j<i+6;j++)
                  check+=line[j];
        }

	if(s1.compare(check)==0)
        {
		        flag=1;
	      }
        if(flag==1)
           cout<<line[i];
        check.clear();
     }
     if(flag==1)cout<<endl;
     flag=0;
 }
  cout<<endl;
  myfile1.open("syslog");
 while(c1!=c)
 {
    getline(myfile1,line);
    c1++;
 }
 cout<<"Date = "<<line[4]<<line[5]<<" ";
 int i,j;
 for(i=0;i<line.size();i++)
 {
    if(i<3)cout<<line[i];
    else break;
 }
 cout<<endl<<"Time = ";
 for(j=7;j<line.size();j++)
 {
     if(j<15)cout<<line[j];
     else break;
 }
 cout<<endl<<"System name = ";
 for(i=j;i<line.size();i++)
 {
     if(i<39)cout<<line[i];
     else break;
 }
 cout<<endl;
 return 0;
}
