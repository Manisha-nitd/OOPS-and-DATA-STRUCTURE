#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main()
{
    int i,j;
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);
    int *a ;
    printf("Enter the numbers :\n");
    a=(int*) malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
     {
         if(k+i<n)
         scanf("%d",&a[k+i]);
         else
            scanf("%d",&a[(k+i)-n]);
     }
printf("enter queries :\n");
    for(j=0;j<q;j++)
    {
        int m;
        scanf("%d",&m);
        printf("%d\n",a[m]);
    }
    return 0;

}
