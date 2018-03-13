#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    int *a = malloc(sizeof(int) * n);
    int a_i,b_i,i,j;
    for(a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for(b_i = 0; b_i < m; b_i++){
       scanf("%d",&b[b_i]);
    }
    int c=0,p=1;
    int x=a[n-1];
    while( x<=b[0])
        {
    for( i=0;i<n;i++)
        {
        p=1;
        if(x%a[i]!=0){
            p=0;
            break;
        }
    }
int z=1;
            if(p)
            {
        for(j=0;j<m;j++)
            {
                z=1;
            if(b[j]%x!=0)
            {
                break;
                z=0;
            }

        }
        if(z)
            c++;
                x++;
            }
    }
        printf("%d",c);
    return 0;
}
