#include <iostream>
using namespace std;
class set
{
	int setsize;
	public:
		int a[100];
		set()
		{
			setsize=0;
		}
		int size()
		{
			return setsize;
		}
		void insert(int);
		void display();

};
void set::insert(int n)
{
 a[setsize]=n;
 setsize++;
}
void set::display()
{
	for(int i=0;i<setsize;i++)
		cout<<"  "<<a[i];
}
void unions(set s1,set s2)
{
	set s3;
	int p=1;
	for(int i=0;i<s1.size();i++)
		s3.insert(s1.a[i]);
	for(int j=0;j<s2.size();j++)
	{
		p=1;
		for(int k=0;k<s3.size();k++)
		{
			if(s2.a[j]==s3.a[k])
			{
				p=0;
				break;
			}
		}
		if(p)
		{
			s3.insert(s2.a[j]);
		}
	}
	cout<<"The union of the two set is :\n";
	s3.display();
}
void intersection(set s1,set s2)
{
	set s3;
	int p=0;
	for(int j=0;j<s2.size();j++)
	{
		p=0;
		for(int k=0;k<s1.size();k++)
		{
			if(s2.a[j]==s3.a[k])
			{
				p=1;
				break;
			}
		}
		if(p)
		{
			s3.insert(s2.a[j]);
		}
	}
	cout<<"The intersection of two set is :\n";
	s3.display();
}
void difference (set s1,set s2)
{
	int p=1;
	set s3;
	for(int j=0;j<s1.size();j++)
	{
		p=1;
		for(int k=0;k<s2.size();k++)
		{
			if(s1.a[j]==s2.a[k])
			{
				p=0;
				break;
			}
		}
		if(p)
		{
			s3.insert(s2.a[j]);
		}
	}
	cout<<"The difference of the two set is (A-B):\n";
	s3.display();
}
bool subset (set s1,set s2)
{
int p=0;
for(int j=0;j<s2.size();j++)
	{
		for(int k=0;k<s1.size();k++)
		{
			if(s1.a[k]==s2.a[j])
			{
				p=1;
				break;
			}
		}
		if(!p)
		{
			return false;
		}
	}
	return true;
	
}
int main()
{
	set s1,s2;
	bool d;
	char w;
	int n,o;
	cout<<"        :SET OPERATION:\n";
	cout<<"Enter the first set A:";
	do
	{
		cout<<"\nEnter the number :";
		cin>>n;
		s1.insert(n);
		cout<<"\nPress 1 to continue and 0 to terminate !";
		cin>>o;
	}while(o==1);
	cout<<"Displayng set A :\n";
	s1.display();
	cout<<"\nEnter the second set B:";
	do
	{
		cout<<"\nEnter the number :";
		cin>>n;
		s2.insert(n);
		cout<<"Press 1 to continue and 0 to terminate !\n";
		cin>>o;
	}while(o==1);
	cout<<"Displaying set B:\n";
	s2.display();
	do
	{
		cout<<"\nEnter your option :";
		cout<<"\n1.UNION\n2.INTERSECTION\n3.DIFFERENCE\n4.SUBSET CHECKING\n";
		cin>>o;
		switch(o)
		{
			case 1:
			unions(s1,s2);
			break;
			case 2:
			intersection(s1,s2);
			break;
			case 3:
			difference(s1,s2);
			break;
			case 4:
			d=subset(s1,s2);
			if(d)
				cout<<"B is the subset of A !";
			else
				cout<<"B is not the subset of A!";
			break;
			default:
			cout<<"Invalid Input!!";
		}
		cout<<"\nTo continue press y/Y";
		cin>>w;
 	}while(w=='y'||w=='Y');
}