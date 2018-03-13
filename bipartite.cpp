#include<iostream>
#include<queue>
using namespace std;
void bipartite(int **a, int v)
{
    int u;
    int set[v];
    for(int i=0;i<v;i++)
    {
        set[i]=-1;
    }
    queue<int> q;
    q.push(0);
    set[0]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int j=0;j<v;j++)
        {
            if(a[u][j]==1 && set[j]==-1)
            {
                set[j]=1-set[u];
                q.push(j);

            }
            else if(a[u][j]==1 && set[j]==set[u] )
            {
                cout<<"The graph is not bipartite !"<<endl;
                return;
            }
        }
    }
cout<<"The graph is bipartite!!"<<endl;
return;
}
int main()
{
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
bipartite(a,v);
return 0;
}

