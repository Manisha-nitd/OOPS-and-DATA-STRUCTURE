#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int a[25];
    FILE* fp=fopen("Numbers.txt","r");
    int i=0,j=0,n;
    scanf("%d",&n);
    while(i<n)
    {

        fscanf(fp,"%d",a[i]);
        printf("%d ,",a[i]);
        i++;
    }
    fclose(fp);
    return 0;
}
