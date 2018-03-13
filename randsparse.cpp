#include<bits/stdc++.h>
using namespace std;
int main()
{
int row,column;
int **a;
cout<<"                    :SPARSE MATRIX GENERATION BY RANDOM FUNCTION:"<<endl;
cout<<"Enter the array dimension (Row and Column) :";
cin>>row>>column;
int c=(row*column)/3;
//taking the density of sparse matrix as 1/4 of the whole matrix
 a=new int*[row];
 for(int j=0;j<row;j++)
 {
    *(a+j)=new int[column];
   for(int i=0;i<column;i++)
   {
     a[j][i]=0;
   }
 }
while(c)
{
 srand(c);
 int i = rand()%row;
 int j =rand()%column;
 a[i][j]=rand()%9+1;
 c--;
 //matrix will have non zero elememt from 1-9.
}
cout<<"DISPLAYING THE SPARSE MATRIX :"<<endl;
for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
        cout<<setw(3)<<a[i][j];
    }
    cout<<endl;
}
return 0;
}
