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
void aop(ll list1,ll list2)
{
    node* temp1=list1.show();
    node* temp2=list2.show();
   int num1,num2;
    num1=0;
    num2=0;
    int i=1;
    while(temp1!=NULL)
    {
        num1=num1+(temp1->data*i);
        i=i*10;
        temp1=temp1->link;
    }
    i=0;
     while(temp2!=NULL)
    {
        num2=num2+temp2->data*pow(10,i);
        i++;
        temp2=temp2->link;
    }
    cout<<"\n\nTHE SUM IS :"<<num1+num2;
    cout<<"\n\nTHE MULTIPLICATION IS :"<<num1*num2;
    cout<<"\n\nTHE DIFFERENCE IS :"<<num1-num2;
    cout<<"\n\nTHE DIVISION IS :";
    if(num1>num2)
        cout<<(float)num1/num2;
    else
       cout<<(float)num2/num1;
}
int main()
{

    ll list1,list2;
    int n,data;
    cout<<"\n               :ARITHMETIC OPERATION USING LINKED LIST:\n";
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
    aop(list1,list2);
}
