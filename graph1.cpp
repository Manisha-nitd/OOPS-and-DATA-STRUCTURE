#include<bits/stdc++.h>
using namespace std;
class graph
{
int a[25][25];
int vertex;
public:
    graph(int v)
    {
        vertex=v;
    }
    void adjacency();
    void dijsktra(int source);
    int mindis(int array[],bool sp[]);
    void display(int distance[]);
    void cluster();
    int ncr(int);
    int factorial(int);
};
int graph::ncr(int n)
{
 return factorial(n)/(2*factorial(n-2));
}
int graph::factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
void graph::display(int distance[])
{
    cout<<"  "<<"VERTEX"<<" "<<"DISTANCE FROM SOURCE"<<endl;
    for(int i=0;i<vertex;i++)
    {
          cout<<"    "<<i<<"      "<<distance[i]<<endl;

    }
}
void graph::adjacency()
{
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cin>>a[i][j];
        }
    }
}
void graph::dijsktra(int source)
{
int distance[vertex];
bool set[vertex];
for(int i=0;i<vertex;i++)
{
    set[i]=false;
    distance[i]=INT_MAX;
}
distance[source]=0;
for(int j=0;j<vertex-1;j++)
{
int u=mindis(distance,set);
set[u]=true;
for(int i=0;i<vertex;i++)
{
    if(set[i]==false && a[u][i] && distance[u]!=INT_MAX &&distance[u]+a[u][i]<distance[i])
        distance[i]=distance[u]+a[u][i];
}
}
display(distance);
}
int graph::mindis(int distance[],bool set[])
{
    int index;
    int min=INT_MAX;
    for(int i=0;i<vertex;i++)
    {
        if(set[i]==false && distance[i]<=min)
        {
            min=distance[i];
            index=i;
        }
    }
    return index;
}
void graph::cluster()
{
    int count=0;
    float sum=0,c=0;
    bool neighbour[vertex];
    int i;
    for(i=0;i<vertex;i++)
    {
        count=0;
         for(int j=0;j<vertex;j++)
        {
            neighbour[j]=false;
        }
        for(int j=0;j<vertex;j++)
        {
            if(a[i][j])
            {
                count++;
                neighbour[j]=true;

            }
        }
        int nc=ncr(count);
        c=0;
        bool dir[vertex][vertex]={false};
        for(int j=0;j<vertex;j++)
        {
            if(neighbour[j]==true)
            {
                for(int k=0;k<vertex;k++)
                {
                    if(a[j][k])
                    {
                        if(k==i)
                            continue;
                        else
                        {
                            if(neighbour[k]==true && dir[j][k]==false)
                            {
                             c++;
                             dir[j][k]==true;
                             dir[k][j]=true;
                            }
                        }
                    }
                }
            }
        }
        float cc=(float)(c/nc);
      cout<<"    "<<i<<"      "<<cc<<endl;
      sum+=cc;
    }
    cout<<"The average custering coefficient is :";
    cout<<(float)(sum/vertex);
}
int main()
{
    int v,source;
    cout<<"Enter the number of vertix of the graph :";
    cin>>v;
    graph g(v);
    cout<<"Enter the adjacency matrix :"<<endl;
    g.adjacency();
    cout<<"\nDIJSKTRA'S ALGORITHM\n";
    cout<<"\nEnter the source index for shortest distance calculation:";
    cin>>source;
    g.dijsktra(source);
    cout<<"\n\n Calculating the clustering coefficient :\n\n";
    cout<<"  "<<"VERTEX"<<" "<<"CLUSTERING COEFFICIENT"<<endl;
    g.cluster();
}
