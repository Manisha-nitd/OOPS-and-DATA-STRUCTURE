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
public:
    ll()
{
    head=NULL;
}
    node* insert(int);
    void display();
    node* show()
    {
        return head;
    }
};

node* ll::insert(int data)
{
    node* newnode= new node;
    newnode->data=data;
    newnode->link=NULL;
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
void setopr(ll list1,ll list2)
{
 ll unn,intsec;
 node* head1=list1.show();
 node* head2=list2.show();
 node*temp=head1;
 while(temp!=NULL)
 {
     unn.insert(temp->data);
     temp=temp->link;
 }
 node* temp2=head2;
 while(temp2!=NULL)//second list
 {
     node* temp1=unn.show();
     int p=1;
     while(temp1!=NULL)//union list
     {
         if(temp2->data==temp1->data)
         {
            intsec.insert(temp2->data);
             p=0;
            break;
         }
         temp1=temp1->link;
     }
     if(p==1)
        unn.insert(temp2->data);
    temp2=temp2->link;
 }
 cout<<"\n\nThe UNION of the set is :";
 unn.display();
 cout<<"\n\nThe INTERSECTION of the set is :";
intsec.display();
}
int main()
{
    ll list1,list2;
    int n,data;
    cout<<"\n               :SET OPERATION USING LINKED LIST:\n";
    cout<<"ENTER THE FIRST LINKED LIST :"<<endl;
    do
    {
     cout<<"\nEnter the number to insert :";
     cin>>data;
     list1.insert(data);
     cout<<"\nPress 1 to continue,0 to exit.";
     cin>>n;
    }while(n==1);
    cout<<"\nTHE FIRST LINKED LIST IS: ";
    list1.display();
    cout<<"\n\nENTER THE SECOND LINKED LIST :"<<endl;
    do
    {
     cout<<"\nEnter the number to insert :";
     cin>>data;
     list2.insert(data);
     cout<<"\nPress 1 to continue,0 to exit.";
     cin>>n;
    }while(n==1);
    cout<<"\nTHE SECOND LIST IS: ";
    list2.display();
    setopr(list1,list2);
    return 0;
}
