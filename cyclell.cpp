#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node* link;

}node;
class ll
{
node* head;
int count;
public:
    ll()
{
    head=NULL;
    count=0;
}
    node* insert(int);
    void display();
    void cycle();
    bool detect();
};

node* ll::insert(int data)
{
    node* newnode= new node;
    newnode->data=data;
    newnode->link=NULL;
	if(head==NULL)
	{
		head=newnode;
		count++;
		return head;

	}
	node* temp;
	temp=head;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newnode;
	count++;
	return head;
}
void ll::display()
{
    node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->link;
	}
	cout<<"NULL";
}
void ll::cycle ()
{
    node *c,*temp=head;
    int p=count/2;
    int n=0;
if(count%2==0)
{
    while(temp->link!=NULL)
    {
     if(n==p)
        c=temp;
     temp=temp->link;
     n++;
    }
    temp->link=c;
}
else
    ;
}
bool ll::detect()
{
    node *fast,*slow;
    fast=slow=head;
    while(fast&&fast->link&&slow->link)
        {
        slow=slow->link;
        fast=fast->link->link;
        if(slow==fast)
            return true;
    }
    return false;
}
int main()
{
    ll list1;
    bool cyc;
    int n,data;
    cout<<"\n               :CYCLE DETECTION IN A LINKED LIST:\n";
    cout<<"ENTER THE LINKED LIST :"<<endl;
    do
    {
     cout<<"\nEnter the number to insert :";
     cin>>data;
     list1.insert(data);
     cout<<"\nPress 1 to continue,0 to exit.";
     cin>>n;
    }while(n==1);
    list1.cycle();
    cyc=list1.detect();
    cout<<"OUTPUT\n";
    if(cyc)
        cout<<"TRUE";
    else
        cout<<"FALSE";
    return 0;
}

