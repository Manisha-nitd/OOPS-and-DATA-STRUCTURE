#include<iostream>
#include<iomanip>
using namespace std;

class set{
  public:
  	int *s;
  	int size;
   public:
   	 set(int x)
   	 {
   	 	size=x;
   	 	s = new int[size];
   	 }
   	 void create();
   	 void display();
};

void set::create()
{
    for(int i=0;i<size;i++)
    {
    	cout<<"Enter element "<<i+1<<" : ";
    	cin>>s[i];
    }
    cout<<endl;
}

void set::display()
{
	for(int i=0;i<size;i++)
		cout<<s[i]<<" ";
	cout<<endl;
}

bool exists(int *a,int n,int d)
{
    for(int i=0;i<n;i++)
    	if(a[i]==d)
    		return true;
    return false;
}

void findUnion(set *s1, set *s2)
{
	int n = s1->size + s2->size;
	int *a=new int[n];
	int i;
	for(i=0;i<s1->size;i++)
		a[i]=s1->s[i];
	int k=s1->size;
	for(int j=i;j<n;j++)
	{
		if(!exists(a,n,s2->s[j-i]))
			a[k++]=s2->s[j-i];
	}
    cout<<"Their Union set is :"<<endl;
	for(int i=0;i<k;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void findIntersection(set *s1,set *s2)
{
	int n = s1->size + s2->size;
	int *a=new int[n];
	int k=-1;
    for(int i=0;i<s1->size;i++)
    {
    	if(exists(s2->s,s2->size,s1->s[i]))
    		a[++k]=s1->s[i];
    }
    cout<<"Their Intersection is :"<<endl;
    if(k==-1)
    	cout<<"Empty!"<<endl;
    else
    {
    for(int i=0;i<=k;i++)
		cout<<a[i]<<" ";}
	cout<<endl;
}

void findDifference(set *s1,set *s2)
{
    cout<<"Set 1 - Set 2 is :"<<endl;
    for(int i=0;i<s1->size;i++)
    {
    	if(!exists(s2->s,s2->size,s1->s[i]))
    		cout<<s1->s[i]<<" ";
    }
    cout<<endl;
    cout<<"Set 2 - Set 1 is :"<<endl;
    for(int i=0;i<s2->size;i++)
    {
    	if(!exists(s1->s,s1->size,s2->s[i]))
    		cout<<s2->s[i]<<" ";
    }
    cout<<endl;
}

void checkSubset(set *s1, set *s2)
{
	cout<<"Subset Check!"<<endl;
    if(s2->size>s1->size)
    {
    	set *t = s2;
    	s2=s1;
    	s1=t;
    }
    for(int i=0;i<s1->size;i+=s2->size)
    {
    	int flag=0;
    	for(int j=i;j<s2->size;j++)
    		{
    			if(exists(s1->s,s1->size,s2->s[j]))
    				flag++;
    		}
    	if(flag==s2->size)
    	{
    		cout<<"The larget set contains the smaller set!"<<endl;
    		return;
    	}
    }
    cout<<"The larger set does not contain the smaller set!"<<endl;
}


int main()
{
	set *s1,*s2;
	cout<<"Enter the size of the first set!"<<endl;
	int n1;
	cin>>n1;
	cout<<"Enter the size of the second set!"<<endl;
	int n2;
	cin>>n2;
	s1 = new set(n1);
	s2 = new set(n2);
	s1->create();
	s2->create();
	cout<<"The Set 1 is :"<<endl;
	s1->display();
	cout<<"The Set 2 is :"<<endl;
	s2->display();
	findUnion(s1,s2);
	findIntersection(s1,s2);
	findDifference(s1,s2);
	cout<<endl;
	checkSubset(s1,s2);
	return 0;
}