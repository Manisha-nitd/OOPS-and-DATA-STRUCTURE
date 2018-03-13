#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
#include<math.h>
using namespace std;
int operation(int op1, int op2, char op)
{
    int ans;
    switch(op){
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    case '^':
        ans=pow(op2,op1);
        break;
    }
    return ans;
}
int priority(char ch)
 {
   switch (ch) {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}
void postfixevaluation(string postfix)
{
    stack<int> e;
    int i,op1,op2;
    int result;
    for(i=0;i<postfix.length();i++)
    {
        if((postfix[i])>=97&& postfix[i]<=122)
        {
            cout<<"Enter the value of "<<postfix[i]<<":"<<endl;
            cin>>postfix[i];
            e.push(postfix[i]-48);
        }
        else if(postfix[i]>=65 && postfix[i]<=90)
        {
            cout<<"Enter the value of "<<postfix[i]<<":"<<endl;
            cin>>postfix[i];
            e.push(postfix[i]-48);
        }
        else if(postfix[i]>=48 && postfix[i]<=57)
            e.push(postfix[i]-48);
        else if(postfix[i]=='^'||postfix[i]=='/'||postfix[i]=='*'||postfix[i]=='+'||postfix[i]=='-')
        {
            op1=e.top();
            e.pop();
            op2=e.top();
            e.pop();
            result= operation(op1,op2,postfix[i]);
            e.push(result);
        }
    }
    cout<<"The postfix expression with values :"<<postfix<<endl;
    cout<<"The result of the postfix evaluation is :"<<e.top();
}
string infixtopostfix(string infix)
{
    int operand=0, operat=0;
    stack<char> s;
    char p[infix.length()-1];
    int i,j=0;
    for(i=0;i<infix.length();i++)
    {
        if (infix[i] == '(')
        {
         s.push(infix[i]);
        }
       else if (infix[i]== ')')
        {
         while ( !s.empty() &&s.top()!='(')
            {
            p[j++]= s.top();
            s.pop();
         }
         if (!s.empty()) {
            s.pop();
         }
      }
      else if(infix[i]=='^'||infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-')
      {
          operat++;
          if(s.empty())
          {
            s.push(infix[i]);
          }
          else
          {
              while(!s.empty()&&priority(s.top())>=priority(infix[i]))
               {
                   p[j++]=s.top();
                   s.pop();
               }
               s.push(infix[i]);
          }
      }
        else if(isdigit(infix[i])||isalnum(infix[i]))
          {
              operand++;
              p[j++]=infix[i];
          }
      }
      while(!s.empty()&& j!=infix.length())
      {
          p[j++]=s.top();
          s.pop();
      }
      cout<<"The number of operand is :"<<operand<<endl;
      cout<<"The number of operator is :"<<operat<<endl;
      return p;

    }
int main()
{
    string infix,postfix;
    cout<<"Enter the infix exression (Without gap) :";
    getline(cin,infix);
    postfix=infixtopostfix(infix);
    cout<<"The postfix expression is :"<<postfix<<endl;
    postfixevaluation(postfix);
    return 0;

}
