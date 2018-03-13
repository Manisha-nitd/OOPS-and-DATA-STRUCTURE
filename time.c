#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int i,len;
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
            len=strlen(time);
    if(time[8]=='P')
        {
            if(time[0]=='1'&&time[1]=='2')
            {;
            }
            else
            {
        time[1]=time[1]+2;
        time[0]=time[0]+1;
            }
        for(i=0;i<len-2;i++)
            printf("%c",time[i]);
    }
    if(time[8]=='A')
    {
      if((time[0]=='1')&&(time[1]=='2'))
      {
          time[0]='0';
          time[1]='0';
      }
          for(i=0;i<len-2;i++)
            printf("%c",time[i]);
    }

    return 0;
}
