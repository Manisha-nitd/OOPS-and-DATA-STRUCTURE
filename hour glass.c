#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){

          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
       int max=0,sum1,sum=0,mid=0;
        int i;
        for(int i=0;i<4;i=i++);
        {
            for(int j=0;j<4;j++)
                {
                 sum=0;
                mid=arr[i+1][j+1];
                for(int k=j;k<3;k++)
                    {
                sum=sum+arr[i][k]+arr[i+2][k];
            }
                sum1=sum+mid;
                if(sum1>max)
                    max=sum1;
        }
    }
        printf("%d",max);
    return 0;
}
