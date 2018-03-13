#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *next;
};


class Stack
{
    struct node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    void push();
    void pop();
    void display();
};

void Stack::push()
{
    int value;
    struct node *ptr;
    cout<<"\nPUSH Operation :\n";
    cout<<"\nEnter a number to insert: ";
    cin>>value;
    ptr=new node;
    ptr->data=value;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;

}


void Stack::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"\nThe stack is empty!!!";
        return ;
    }
    temp=top;
    top=top->next;
    cout<<"\nPOP Operation :\nPoped value is :"<<temp->data;
    delete temp;
}


void Stack::display()
{
    struct node *ptr1=top;
    cout<<"\nDisplaying the stack:";
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<" ->";
        ptr1=ptr1->next;
    }
    cout<<"NULL\n";
}


int main()
{
    Stack s;
    int choice;
    cout<<"\n\t\tSTACK USING LINKED LIST";
    while(1)
    {
        cout<<"\n\n1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT";
        cout<<"\n\nEnter your choice: ";

        cin>>choice;

        switch(choice)
        {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\n Wrong Choice !!!\n";
                break;
        }
    }
    return 0;
}
