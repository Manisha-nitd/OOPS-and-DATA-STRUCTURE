#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int pow;
    float coeff;
    struct node *next;
}node;
node* getnode()
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    return newnode;
}
node* poly()
{
    node *newnode,*temp,*head;
    int c;
    head=NULL;
    printf("Enter the polynomial with decreasing power :\n");
    do{
    newnode=getnode();
    printf("Enter power :");
    scanf("%d",&newnode->pow);
    printf("\nEnter coefficient: ");
    scanf("%f",&newnode->coeff);
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
        printf("\nWant to Enter more ?? enter 1\n");
        scanf("%d",&c);
}while(c==1);
return head;
}
node* add(node *head1,node *head2)
{
    node *newnode,*head=NULL,*temp;
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
void display(node *head)
{
while(head!=NULL)
{
    printf("%.1f x^%d",head->coeff,head->pow);
    head=head->next;
    printf("+");
}
printf("\b");
}
int main()
{
    node *head1,*head2,*headsum,*headdif,*head;
    printf("Enter the first polynomial :\n");
    head1=poly();
    display(head1);
    printf("\n\nEnter the second polynomial :\n");
    head2=poly();
    display (head2);
    head=add(head1,head2);
    printf("\nThe added polynomial is :\n");
    display(head);
return 0;
}
