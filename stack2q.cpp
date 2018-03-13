#include<iostream>
#include<cstdlib>

using namespace std;
int emp;
struct node{
    int data;
    struct node *next;
};

class Queue{
    public:
        node *front;
        node *rear;
        Queue();
        void enqueue(int);
        int dequeue();
        bool isempty();
};

Queue::Queue()
{
    rear = NULL;
    front = NULL;
}
void Queue::enqueue(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
        rear=temp;
    }
    else
    {
    rear->next = temp;
    }
    rear = temp;
}
int Queue::dequeue()
{
    ::emp=1;
    node *temp = new node;
    if(front == NULL)
    {
        cout<<"\nSTACK IS EMPTY!!!!!!!\n";
        ::emp=0;
        return 0;
    }
    if(front==rear)
    {
        temp=front;
        int num=temp->data;
        front=NULL;
        rear=NULL;
        delete temp;
        return num;
    }
    else
        {
        temp = front;
        front = front->next;
       int num=temp->data;
        delete temp;
        return num;
    }

}
bool Queue::isempty()
{
    if(front==NULL)
        return true;
    else
        return false;
}
typedef struct stack
{
    Queue q1,q2;
    //using two queues to implement stack;
}S;
void push(S* stk,int data)
{
 if(stk->q1.isempty())
        stk->q2.enqueue(data);
 else
    stk->q1.enqueue(data);
}
int pop(S* stk)
{
    if(stk->q1.isempty())
    {
        while(stk->q2.rear!=stk->q2.front)
           stk->q1.enqueue(stk->q2.dequeue());
       return stk->q2.dequeue();
    }
    else
    {
      while(stk->q1.rear!=stk->q1.front)
           stk->q2.enqueue(stk->q1.dequeue());
       return stk->q1.dequeue();
    }
}
int main()
{

    S stk;
    int choice,value;
    cout<<"---------------------STACK USING TWO QUEUES --------------------";
    while(true)
        {
        cout<<"\n1.PUSH\n2.POP\n3.QUIT";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter the value to be PUSHed :";
                cin>>value;
                push(&stk,value);
                break;
            case 2:
               value=pop(&stk);
               if(::emp || value)
               cout<<"\nThe POPed value is :"<<value;
               cout<<endl;
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Input. Try again! \n";
                break;
        }
    }
    return 0;

}
