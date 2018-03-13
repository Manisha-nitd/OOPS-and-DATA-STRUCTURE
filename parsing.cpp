#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
using namespace std;
int top=-1;
int arr[100];
int priority(char c)
{
    if(c=='^')
        return 4;
   else if(c=='*'||c=='/')
        return 3;
    else if(c=='+'||c=='-')
        return 2;
    else
        return 1;
}
void push(int k)
{
    top++;
    arr[top]=k;
}
int pop()
{
    if(top==-1)
        return 0;
    int k=arr[top];
    top--;
    return k;
}
void postfix(string exp)
{
    stack<char> s;
    string postfix="";
    for(i=0;i<exp.len();i++)
    {
        if(isalnum(s[i]))
            postfix.st
        if(ar[i]=='+'||ar[i]=='-'||ar[i]=='*'||ar[i]=='/'||ar[i]=='^')
        {
            if(top!=-1)
            {
                char sym;
                sym=pop();
                while(priority(sym)>=priority(ar[i]))
                {
                    printf("%c",sym);
                    sym=pop();
                }
                push(ar[i]);
            }
        }
        if(ar[i]=='(')
            push(arr[i]);
        if(ar[i]==')')
        {
            char num=0;
            while(num!='(')
            {
                num=pop();
                printf("%c",num);
            }
        }
    }
    while(top!=-1)
    {
        int k=pop();
        printf("%c",k);
    }
}
int main()
{
    string postfix, infix;
    cout<<"Enter the infix expression :"<<endl;
    getline(cin,infix);
    postfix=postfix(infix);
    cout<<"The postfix expression is :"<<postfix<<endl;
    return 0;

}
