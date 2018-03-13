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
    void push(int);
    int pop();
    bool isempty();

};
void Stack::push(int data)
{
    int value;
    struct node *ptr;
    ptr=new node;
    ptr->data=data;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;

}


int Stack::pop()
{
    int num;
    struct node *temp;
    if(isempty())
    {
        cout<<"\nERROR!! The queue is empty!!\n"<<endl;
        return 0;
    }
    temp=top;
    top=top->next;
    num=temp->data;
    delete temp;
    return num;
}
 bool Stack::isempty()
 {
     if(top==NULL)
        return true;
     else
        return false;
 }
typedef struct Queue
{
    Stack s1,s2;
    //two stacks are used to implement queue
}Q;
void enqueue(Q* que,int data)
{
    que->s1.push(data);
}
int dequeue(Q* que)
{
if(!que->s2.isempty())
    return que->s2.pop();
else
{
    while(!que->s1.isempty())
        que->s2.push(que->s1.pop());
    return que->s2.pop();
}
}
int main()
{
    Q que ;
    int choice,value;
    cout<<"\n\t\tQUEUE USING TWO STACKS :";
    while(1)
    {
        cout<<"\n\n1:ENQUEUE\n2:DEQUEUE\n3:EXIT";
        cout<<"\n\nEnter your choice: ";

        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nEnter a number to insert: ";
                cin>>value;
                enqueue(&que,value);
                break;
            case 2:
                value=dequeue(&que);
                if(value)
                cout<<"\nThe DEQUEUED value is :"<<value;
                break;
            case 3:
                return 0;
                break;
            default:
                cout<<"\n Wrong Choice !!!\n";
                break;
        }
    }
     return 0;
}
