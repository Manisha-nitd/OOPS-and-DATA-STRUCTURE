#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int row,column,k;
float **a,**b;
int c=0;
cout<<"                 :TRANSPOSE OF A SPARSE MATRIX:\n";
cout<<"\nEnter the array dimension(Row and Column): ";
cin>>row>>column;
a=new float*[row];
cout<<"\nEnter the values of array :"<<endl;
for(int i=0;i<row;i++)
    {
    *(a+i)=new float[column];
    for(int j=0;j<column;j++)
       {
         cin>>(*(*(a+i)+j));
         if((*(*(a+i)+j))!=0)
            c++;
       }
    }
cout<<"\n\nDisplaying the sparse matrix in triplet form :"<<endl;
cout<<"  "<<"Row"<<"  "<<"Column"<<"  "<<"Value"<<endl;
cout<<"   "<<row<<"     "<<column<<"       "<<c<<endl;
b=new float*[c+1];
*(b+0)=new float[3];
b[0][0]=row;
b[0][1]=column;
b[0][2]=c;
k=1;
for(int i=0;i<row;i++)
    {
    for(int j=0;j<column;j++)
        {
        *(b+k)=new float[3];
        if((*(*(a+i)+j))!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k++][2]=(*(*(a+i)+j));
             cout<<"   "<<i<<"     "<<j<<"       "<<(*(*(a+i)+j))<<endl;
             }
        }
    }
//generating sparse matrix from triplet form
float** sp;
sp=new float*[(int)b[0][0]];
for(int i=0;i<b[0][1];i++)
{
*(sp+i)=new float[(int)b[0][1]];
}
for(int i=0;i<b[0][0];i++)
    {
        for(int j=0;j<b[0][1];j++)
            sp[i][j]=0;
    }
for(int i=1;i<=c;i++)
{
sp[(int)b[i][0] ][(int)b[i][1]]=b[i][2];
}
cout<<"\n\nDisplaying the sparse matrix :"<<endl;
for(int i=0;i<b[0][0];i++)
    {
    for(int j=0;j<b[0][1];j++)
            cout<<setw(4)<<sp[i][j];
    cout<<endl;
    }
float temp;
for(int i=0;i<=c;i++)
    {
         temp=b[i][0];
         b[i][0]=b[i][1];
         b[i][1]=temp;
    }
cout<<"\n\nDisplaying the transpose of sparse matrix in triplet form :"<<endl;
cout<<"  "<<"Row"<<"  "<<"Column"<<"  "<<"Value"<<endl;
for(int i=0;i<=c;i++)
    {
        cout<<"   "<<b[i][0]<<"     "<<b[i][1]<<"       "<<b[i][2]<<endl;
    }
//generating sparse matrix(transpose) from triplet form
for(int i=0;i<b[0][0];i++)
    {
        for(int j=0;j<b[0][1];j++)
            sp[i][j]=0;
    }
for(int i=1;i<=c;i++)
{
sp[(int)b[i][0] ][(int)b[i][1]]=b[i][2];
}
cout<<"\n\nDisplaying the transpose of sparse matrix :"<<endl;
for(int i=0;i<b[0][0];i++)
    {
    for(int j=0;j<b[0][1];j++)
            cout<<setw(4)<<sp[i][j];
    cout<<endl;
    }
return 0;
}


