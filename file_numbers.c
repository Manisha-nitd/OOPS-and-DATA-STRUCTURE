#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[25];
    FILE *fp;
    fp=fopen("Numbers.txt","w");
    int i=0;
    while(i<25)
    {
        int k;
        printf("Enter number :");
        scanf("%d",&k);
        fprintf(fp,"%d\n",k);
        i++;
    }
    fclose(fp);
    return 0;
}
