#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left,*right;

}node;
class tree
{
    node* root;
    int counter;
public:
    tree()
    {
        root=NULL;
        counter=0;
    }
    void insert(int);
    void inorder(node*);
    void intrav();
    void preorder(node*);
    void pretrav();
    void postorder(node*);
    void posttrav();
    void levelorder(node*,int);
    void levtrav();
    int ht();
    int height(node*);
    int count(node*);
    void ct();
    void boundary(node*);
    void bd();
    void boundaryleft(node*);
    void printleaves(node*);
    void boundaryright(node*);
};
void tree::insert(int data)
{
    node* newnode= new node;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
	if(root==NULL)
	{
	    counter++;
		root=newnode;
		return;
	}
	node *temp,*parent;
	temp=root;
	while(temp!=NULL)
    {
        parent=temp;
        if(data<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(data<parent->data)
        parent->left=newnode;
    else
        parent->right=newnode;
    counter++;
    return;
}
void tree::pretrav()
{
    cout<<"\nThe preorder traversal is :";
    preorder(root);
}
void tree ::preorder(node *temp)
{
     if (root==NULL)
    {
        cout<<"The tree is empty!!";
        return;
    }
    if(temp!=NULL)
    {
        cout<<"  "<<temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void tree::posttrav()
{
    cout<<"\nThe post order traversal is :";
    postorder(root);
}
void tree ::postorder(node *temp)
{
     if (root==NULL)
    {
        cout<<"The tree is empty!!";
        return;
    }
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<"  "<<temp->data;
    }
}
void tree::intrav()
{
    cout<<"\nThe inorder traversal is :";
    inorder(root);
}
void tree ::inorder(node *temp)
{
    if (root==NULL)
    {
        cout<<"The tree is empty!!";
        return;
    }
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<"  "<<temp->data;
        inorder(temp->right);
    }
}
int tree::ht()
{
   int h=height(root);
    return h;
}
int tree::height(node* root)
{
     if (root==NULL)
       return 0;
   else
   {
       int lDepth = height(root->left);
       int rDepth = height(root->right);
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
void tree::levtrav()
{
    int h=ht();
    int i;
    cout<<"\nThe levelorder traversal is :";
    for(i=1;i<=h;i++)
        levelorder(root,i);
}
void tree ::levelorder(node *root,int level)
{
if(root==NULL)
   return;
else if(level==1)
    cout<<" "<<root->data;
else if(level>1)
{
    levelorder(root->left,level-1);
    levelorder(root->right,level-1);
}
}
void tree::ct()
{
    int c=count(root);
    cout<<"\nThe number of leaf nodes are :"<<c;
    cout<<"\nThe number of internal nodes are:"<<counter-c;
}
void tree::bd()
{
    cout<<"\n The boundary order traversal is :";
    boundary(root);
}
void tree::boundary(node* root)
{
    if (root)
    {
        cout<<" "<<root->data;
        boundaryleft(root->left);

        printleaves(root->left);
        printleaves(root->right);

        boundaryright(root->right);
    }
}
void tree::boundaryleft(node* root)
{
    if(root)
    {
        if(root->left)
        {
            cout<<" "<<root->data;
            boundaryleft(root->left);
        }
        else if(root->right)
        {
            cout<<" "<<root->data;
            boundaryleft(root->right);
        }
    }
}
void tree::boundaryright(node* root)
{
    if(root)
    {
        if(root->right)
        {
            boundaryright(root->right);
             cout<<" "<<root->data;
        }
        else if(root->left)
        {
            boundaryright(root->right);
              cout<<" "<<root->data;
        }
    }
}
void tree::printleaves(node* root)
{
    if(root)
    {
        printleaves(root->left);
        printleaves(root->right);
        if(!(root->left) && !(root->right))
            cout<<" "<<root->data;

    }
}
int tree::count(node* node)
{
     if(node == NULL)
    return 0;
    if(node->left == NULL && node->right==NULL)
    return 1;
    else
    return count(node->left)+
           count(node->right);
}
int main()
{
    int n,p,num;
    char ch;
    tree t;
cout<<"Create a tree :\n";
do
{
    cout<<"Enter the number to be inserted :";
    cin>>num;
    t.insert(num);
    cout<<"Want to enter more ? Press y/Y :" ;
    cin>>ch;
}while(ch=='y'||ch=='Y');
while(1)
{
cout<<"\n\n              :OPERATIONS:              \n";
cout<<"1.INORDER TRAVERSAL\n2.PREORDER TRAVERSAL\n3.POSTORDER TRAVERSAL\n4.LEVELORDER TRAVERSAL\n5.HEIGHT";
cout<<"\n6.BOUNDARY TRAVERSAL\n7.COUNT LEAF AND INTERNAL NODES\n8.EXIT\n";
cin>>n;
    switch(n)
{
case 1:
    t.intrav();
    break;
case 2:
    t.pretrav();
    break;
case 3:
    t.posttrav();
    break;
case 4:
    t.levtrav();
    break;
case 5:
    p=t.ht();
    cout<<"The height of the tree is :"<<p;
    break;
case 6:
    t.bd();
    break;
case 7:
    t.ct();
    break;
case 8:
    exit(1);
default:
    cout<<"\nINVALID CHOICE!!\n";
}
}
return 0;
}
