#include<bits/stdc++.h>
using namespace std;
class heap
{
    vector<int> v;
public:
    heap()
    {
    }
    void push();
    void pop();
    void sort();
    void display();
    int leftchild(int);
    int rightchild(int);
    int parent(int);
    void percolateup(int);
    void percolatedown(int);
};
int heap::leftchild(int i)
{
    int left=2*i+1;
    if(left>=v.size())
        return -1;
    else
        return left;
}
int heap::rightchild(int i)
{
    int right=2*i+2;
    if(right>=v.size())
        return -1;
    else
        return right;
}
int heap:: parent(int i)
{
    int p=(i-1)/2;
    if(i==0)
        return -1;
    else
        return p;
}
void heap::push()
{
    int num;
    cout<<"Enter the element of heap:";
    cin>>num;
    v.push_back(num);
    percolateup(v.size()-1);
}
void heap::percolateup(int j)
{
    int temp;
    if(j>=0 && parent(j)>=0 && v[parent(j)]>v[j])
    {
       temp= v[j];
       v[j]=v[parent(j)];
        v[parent(j)]=temp;
        percolateup(parent(j));
    }
}
void heap::percolatedown(int i)
{
int l=leftchild(i);
int r=rightchild(i);
int temp;
if(l!=-1 && r!=-1 && v[l]>v[r])
    l=r;
if (l > 0 && v[i] > v[l])
    {
        temp = v[i];
        v[i] = v[l];
        v[l] = temp;
        percolatedown(l);
    }
}
void heap::pop()
{
    if(v.empty())
    {
        cout<<"The heap is empty!";
        return;
    }
    v[0]=v[(v.size()-1)];
    v.pop_back();
    percolatedown(0);
}
void heap::display()
{
    vector<int>::iterator i;
    for(i=v.begin();i<v.end();i++)
        cout<<" "<<*i;
}
void heap::sort()//the heap is deleted during sorting
{
    cout<<"Displaying the sorted heap :";
   int i=v.size();
    while(i--)
    {
        cout<<" "<<v[0];
        pop();
    }
}
int main()
{
    heap h;
    int n,o;
    cout<<"                         :HEAP:\n\n";//creating a minimun heap
    cout<<"The Heap Operations are:\n";
while(1)
{
    cout<<"\n1.PUSH\n2.POP\n3.SORT\n4.DISPLAY\n5.EXIT\n";
    cin>>o;
    switch(o)
    {
    case 1:
        h.push();
        break;
    case 2:
        h.pop();
        break;
    case 3:
        h.sort();
        break;
    case 4:
        cout<<"Displaying the heap :";
        h.display();
        break;
    case 5:
        exit(1);
        break;
    default:
        cout<<"Invalid choice ! Try again!";
    }
}
}
