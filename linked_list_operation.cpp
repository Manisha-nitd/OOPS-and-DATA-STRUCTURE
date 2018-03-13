#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class node
{
 public:
 int data;
 node *next;
 node (void)
 {
  data=0;
  next=NULL;
 }
 node (int x)
 {
  data=x;
  next=NULL;
 }
 node (int x,node *p)
 {
  data=x;
  next=p;
 }
 ~node()
 {
  cout<<"delete";
 }
};
class sll
{
 public:
 node *hl;
 int n;
 sll(void)
 {
  hl=NULL;
  n=0;
 }
 sll(int x)
 {
  hl=new node(x);
  n=1;
 }
 void insertend(int x)
 {
  node *temp;
  node *t=new node(x);
  if (hl==NULL)
  {
   hl=t;
   n++;
  }
  else
  {
   temp=hl;
   while (temp->next!=NULL)
    temp=temp->next;
   temp->next=t;
   n++;
  }
 }
int sum()
{
 node *a=hl;
 int c=0;
 int sum1=0;
 while (a!=NULL)
 {
  sum1=sum1+((a->data)*pow(10,c));
  c=c+1;
  a=a->next;
 }
 return sum1;
}
 void display()
 {
  node *t=hl;
  while(t!=NULL)
  {
   cout<<t->data<<"-->";
   t=t->next;
  }
 cout<<endl;
}

 void rotate(int x)
  {
   int c=1;
   node *temp;
   node *temp2;
   node *temp3;
   if (hl==NULL)
    cout<<"NULL";
   else
   {
    temp=hl;
    while (c!=x)
    {
     temp=temp->next;
     c=c+1;
    }
    temp3=temp;
    if (x>c)
     cout<<"Less no of elements in the list";
    else
    {
    while (temp!=NULL)
    {
     cout<<temp->data<<"-->";
     temp=temp->next;
    }
    temp2=hl;
    while (temp2!=temp3)
    {
     cout<<temp2->data<<"-->";
     temp2=temp2->next;
    }
    cout<<"NULL";
    }
   }
  }
 void union_list(node *h)
 {
  node *temp1=hl;
  node *temp2=h;
  node *temp3=hl;
  int flag=0;
  while (temp1!=NULL)
  {
    cout<<temp1->data<<"-->";
    temp1=temp1->next;
  }
  while (temp2!=NULL)
  {
   while (temp3!=NULL)
   {
    if (temp2->data==temp3->data)
    {
     flag=1;
     break;
    }
    temp3=temp3->next;
   }
  if (flag==0)
   cout<<temp2->data<<"-->";
  temp2=temp2->next;
  temp3=hl;
 flag=0;
  }
 cout<<endl;
 }
 void intersection (node *h)
 {
  node *temp1=hl;
  node *temp2=h;
  while (temp1!=NULL)
  {
   while (temp2!=NULL)
   {
    if (temp1->data==temp2->data)
     {
     cout<<temp1->data<<"-->";

     }
    temp2=temp2->next;
   }
  temp1=temp1->next;
  temp2=h;
  }
 cout<<endl;
 }
 int check()
 {

};
int main ()
{
 sll s1;
 sll s2;
 int c,n,m;
 cout<<"enter 1 to insert an element in list 1"<<endl;
 cout<<"enter 2 to insert an element in list 2"<<endl;
 cout<<"enter 3 to find the sum"<<endl;
 cout<<"enter 4 to find the difference"<<endl;
 cout<<"enter 5 to find the multiplication"<<endl;
 cout<<"enter 6 to find the division"<<endl;
 cout<<"enter 7 to exit"<<endl;
 cout<<"enter 8 to display the list"<<endl;
 cout<<"enter 9 to rotate list 1"<<endl;
 cout<<"enter 10 to rotate list 2"<<endl;
 cout<<"enter the case"<<endl;
 cin>>c;
 while (c!=7)
 {
 switch(c)
 {
  case 1:
   {
    cout<<"enter the element to be inserted in list 1"<<endl;
    cin>>n;
    s1.insertend(n);
   }
   break;
  case 2:
   {
    cout<<"enter the element to be inserted in list 2"<<endl;
    cin>>m;
    s2.insertend(m);
   }
   break;
  case 3:
  {
   int a=s1.sum()+s2.sum();
   cout<<"sum="<<a<<endl;
  }
  break;
  case 4:
   {
    cout<<"difference="<<(s1.sum()-s2.sum())<<endl;
   }
   break;
  case 5:
   {
    cout<<"multiplication="<<(s1.sum()*s2.sum())<<endl;
   }
   break;
  case 6:
   {
    cout<<"division="<<(s1.sum()/s2.sum())<<endl;
   }
   break;
  case 8:
   {
    s1.display();
    s2.display();
   }
  break;
  case 9:
   {
    cout<<"enter the point of rotation for list 1"<<endl;
    cin>>n;
    s1.rotate(n);
   }
   break;
  case 10:
   {
    cout<<"enter the point of rotation for list 2"<<endl;
    cin>>n;
    s1.rotate(n);
   }
   break;
  }
 cout<<"enter the case"<<endl;
 cin>>c;

 }
 sll s3,s4;
 c=0;
 cout<<"Enter 1 to insert elements in list 1"<<endl;
 cout<<"enter 2 to insert elements in list 2"<<endl;
 cout<<"enter 3 to find union"<<endl;
 cout<<"enter 4 to find intersection"<<endl;
 cout<<"enter 5 to exit"<<endl;
 cin>>c;
 while (c!=5)
 {
 switch(c)
 {
  case 1:
   {
    cout<<"enter the element to be inserted in list 1"<<endl;
    cin>>n;
    s3.insertend(n);
   }
   break;
  case 2:
   {
    cout<<"enter the element to be inserted in list 2"<<endl;
    cin>>m;
    s4.insertend(m);
   }
  break;
  case 3:
   {
    s3.union_list(s4.hl);
   }
   break;
  case 4:
   {
    s3.intersection(s4.hl);
   }
   break;
 }
 cout<<"enter the case"<<endl;
 cin>>c;
 }
 sll s;
}

 return 0;
}


