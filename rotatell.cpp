#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef struct node
{
int data;
struct node* link;
}node;

node* newnd(int data)
{
	node* temp=new node;
	temp->data=data;
	temp->link=NULL;
	return temp;
}
void display(node* head)
{
	node* temp= head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->link;
	}
	cout<<"NULL";
}
node* rotate(node* head,int k)
{
	if(head==NULL)
	{
		cout<<"\nLinked List is empty!!\n";
		return NULL ;
	}
	node* temp;
	node* temp1;
	temp=head;
	k=k-1;
	while(k-- && temp)
	{
		temp=temp->link;
	}
	if(!temp)
    {
        cout<<"\nLess no of elements in the list!!\n";
    }
    else
    {
	temp1=temp->link;
	temp->link=NULL;
	temp=temp1;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=head;
	head=temp1;
    }
	return head;
}
node* insert(node* head,int data)
{
	node* newnode= newnd(data);
	if(head==NULL)
	{
		head=newnode;
		return head;

	}
	node* temp;
	temp=head;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newnode;
	return head;
}
node* head=NULL;
int main()
{
	int num,k;
	while(1)
	{
		cout<<"\nLINKED LIST OPERATION :"<<endl;
		cout<<"1.INSERT\n2.ROTATE\n3.DISPLAY \n4.EXIT\n";
		int o;
		cin>>o;
		switch(o)
		{
			case 1:
			cout<<"\nEnter the number to insert :";
			cin>>num;
			head=insert(head,num);
			break;
			case 2:
			cout<<"\n Insert the rotating factor :";
			cin>>k;
			head=rotate(head,k);
			break;
			case 3:
			cout<<"\nDisplaying the linked list :\n";
			display(head);
			break;
			case 4:
			exit(1);
			default:
			cout<<"\nINVALID INPUT . TRY AGAIN!!\n";

		}
	}
}
