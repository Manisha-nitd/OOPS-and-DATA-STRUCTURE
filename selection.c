#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[25];
    int i,j,n,temp,min=0;
    printf("Enter the array dimension :\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
     printf("The sorted array :\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;

}
