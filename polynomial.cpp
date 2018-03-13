#include<iostream>
using namespace std;
typedef struct node
{
    int pow;
    float coeff;
    struct node *next;
}node;
node* getnode()
{
    node* newnode;
    newnode=new node;
    newnode->next=NULL;
    return newnode;
}
node* poly(int n)
{
    node *newnode,*temp,*head;
    int c;
    head=NULL;
    cout<<"Enter the polynomial with decreasing power :\n";
    while(n)
    {
    newnode=getnode();
    cout<<"Enter degree:";
    cin>>newnode->pow;
    cout<<"\nEnter coefficient: ";
    cin>>newnode->coeff;
    if(head==NULL)
       {
        head=newnode;
        temp=head;
       }
    else
    {
    temp->next=newnode;
    temp=newnode;
    }
    n--;
}
return head;
}
node* add(node *hd1,node *hd2)
{
    node *newnode,*head=NULL,*temp,*head1,*head2;
    head1=hd1;
    head2=hd2;
    while(head1!=NULL && head2!=NULL)
    {
        newnode=getnode();
        if(head1->pow>head2->pow)
    {
        newnode->coeff=head1->coeff;
        newnode->pow=head1->pow;
        head1=head1->next;
    }
   else if(head2->pow>head1->pow)
    {
        newnode->coeff=head2->coeff;
        newnode->pow=head2->pow;
        head2=head2->next;
    }
    else
    {
        newnode->pow=head1->pow;
        newnode->coeff=head1->coeff+head2->coeff;
        head1=head1->next;
        head2=head2->next;

    }
    if(head==NULL)
    {
        head=newnode;
        temp=head;
    }
    else{
    temp->next=newnode;
        temp=newnode;
    }
    }
    if(head1==NULL)
    {
        if(head==NULL)
        {
            head=head2;
        }
        else
        {
            while(head2!=NULL)
            {
                newnode=getnode();
                newnode->pow=head2->pow;
                newnode->coeff=head2->coeff;
                temp->next=newnode;
                temp=newnode;
                head2=head2->next;

            }
        }
    }
        if(head2==NULL)
    {
        if(head==NULL)
        {
            head=head1;
        }
        else
        {
            while(head1!=NULL)
            {
                newnode=getnode();
                newnode->pow=head1->pow;
                newnode->coeff=head1->coeff;
                temp->next=newnode;
                temp=newnode;
                head1=head1->next;

            }
        }
    }
return head;
}
node* dif(node *hd1,node *hd2)
{
    node *newnode,*head=NULL,*temp,*head1,*head2;
    head1=hd1;
    head2=hd2;
    while(head1!=NULL && head2!=NULL)
    {
        newnode=getnode();
        if(head1->pow>head2->pow)
    {
        newnode->coeff=head1->coeff;
        newnode->pow=head1->pow;
        head1=head1->next;
    }
   else if(head2->pow>head1->pow)
    {
        newnode->coeff=head2->coeff;
        newnode->pow=head2->pow;
        head2=head2->next;
    }
    else
    {
        newnode->pow=head1->pow;
        newnode->coeff=head1->coeff-head2->coeff;
        head1=head1->next;
        head2=head2->next;

    }
    if(head==NULL)
    {
        head=newnode;
        temp=head;
    }
    else{
    temp->next=newnode;
        temp=newnode;
    }
    }
    if(head1==NULL)
    {
        if(head==NULL)
        {
            head=head2;
        }
        else
        {
            while(head2!=NULL)
            {
                newnode=getnode();
                newnode->pow=head2->pow;
                newnode->coeff=head2->coeff;
                temp->next=newnode;
                temp=newnode;
                head2=head2->next;

            }
        }
    }
        if(head2==NULL)
    {
        if(head==NULL)
        {
            head=head1;
        }
        else
        {
            while(head1!=NULL)
            {
                newnode=getnode();
                newnode->pow=head1->pow;
                newnode->coeff=head1->coeff;
                temp->next=newnode;
                temp=newnode;
                head1=head1->next;

            }
        }
    }
return head;
}

void display(node *head)
{
    node* temp=head;
    while(temp!=NULL)
    {
    cout<<temp->coeff<<"x^"<<temp->pow;
    temp=temp->next;
    cout<<"+";
    }
}
int main()
{
    node *head1,*head2,*headsum,*headdif;
    int n1,n2;
    cout<<"                       :POLYNOMIAL OPERATION:\n\n";
    cout<<"Enter the number of terms of first polynomial :\n";
    cin>>n1;
    head1=poly(n1);
    cout<<"\n\nEnter the number of terms of second polynomial :\n";
    cin>>n2;
    head2=poly(n2);
    cout<<"\nDisplaying the first polynomial :";
    display(head1);
    cout<<"\nDisplaying the second polynomial :";
    display (head2);
    headsum=add(head1,head2);
    headdif=dif(head1,head2);
    cout<<"\n\nThe added polynomial is :\n";
    cout<<"SUM:";
    display(headsum);
    cout<<"\n\nThe difference of the polynomial is :\n";
    cout<<"DIFFERENCE:";
    display(headdif);
return 0;
}
