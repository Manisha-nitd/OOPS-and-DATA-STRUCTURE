#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
void component(int **a, int v)
{
    int counter=0;
    bool visit [v];
    stack<int> s;
   for(int j=0;j<v;j++)
    {
      if(visit[j]==0)
      {
          counter++;
          s.push(j);
          visit[j]=1;
          while(!s.empty())
            {
            int i=s.top();
            int p=0;
                for(int j=0;j<v;j++)
                    {
                    if(a[i][j]==1 && visit[j]==0)
                        {
                        visit[j]=1;
                        s.push(j);
                        p=1;
                        break;
                        }
                    }
                if(p==0)
                s.pop();
            }
      }
    else
        continue;
}
cout<<"The number of components are :"<<counter<<endl;
}
void dfs (int **a, int v)
{
    bool visit [v];
    stack<int> s;
    cout<<"DFS traversal :"<<endl;
    for(int j=0;j<v;j++)
    {
    if(visit[j]==0)
    {
    s.push(j);
    visit[j]=1;
    cout<<setw(4)<<s.top();
    while(!s.empty())
    {
   int i=s.top();
   int p=0;
    for(int j=0;j<v;j++)
    {
        if(a[i][j]==1 && visit[j]==0)
        {
            visit[j]=1;
            s.push(j);
            cout<<setw(4)<<s.top();
            p=1;
            break;
        }
    }
if(p==0)
    s.pop();
}
    }
else
    continue;
}
}
void bfs(int **a, int v)
{
    bool visit[v];
    queue<int> q;
    cout<<"BFS traversal :"<<endl;
    for(int j=0;j<v;j++)
    {
    if(visit[j]==0)
    {
    q.push(j);
    visit[j]=1;
    while(!q.empty())
    {
       int i=q.front();
        for(int j=0;j<v;j++)
        {
            if(a[i][j]==1)
            {
                if(visit[j]==0)
                {
                    q.push(j);
                    visit[j]=1;
                }
            }
        }
        cout<<setw(4)<<q.front();
        q.pop();
    }
    }
    else
        continue;
    }
}
int main()
{
    stack<int> s;
    int v,**a,c;
    cout<<"Enter the number of vertices :"<<endl;
    cin>>v;
    a=new int*[v];
    cout<<"Enter the adjacency matrix :"<<endl;
    for(int i=0;i<v;i++)
    {
        *(a+i)=new int[v];
        {
            for(int j=0;j<v;j++)
                cin>>a[i][j];
        }
    }
do{
cout<<"Enter option for the following :"<<endl;
cout<<"1.BFS"<<endl<<"2.DFS"<<endl<<"3.Component calculation"<<endl;
int n;
cin>>n;
switch(n)
{
case 1:
    bfs(a,v);
    break;
case 2:
  dfs(a,v);
    break;
case 3:
    component(a,v);
    break;
default:
    cout<<"Wrong Choice !!"<<endl;
}
cout<<endl<<"Want some other operation ?? Press 1 ."<<endl;
cin>>c;
}while(c==1);
return 0;
}
