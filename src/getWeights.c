#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int m=0,v=0,i=0,j=0,k=0,a=-1,b=0,c=0,d=0;
    char str[100][100],str1[100][100],character;
    int str2[100],sum[100];
    for(i=0;(character=getchar())!=EOF;i++)
    {
        if(character!=' ')
        {
            if((isalpha(character)||isdigit(character)) && (d==0))
            {
                if(c==1)
                {
                    c=0;
                    str1[a][b]='\0';
                    b=0;
                }
                str[j][k++]=character;
            }
            else if(isdigit(character))
            {
                c=1;
                str1[a][b++]=character;
            }
            else
                d=0;
        }
        else
        {
            d=1;
            a++;
            str[j++][k]='\0';
            k=0;
        }
    }
    str1[a][b]='\0';
    for(i=0;i<j;i++)
    {
        str2[i]=atoi(str1[i]);
        if(i<j/3)
            sum[i]=str2[i];
    }
    for(i=0;i<j/3;i++)
    {
        for(m=j/3;m<2*j/3;m++)
            if(!strcmp(str[i],str[m]))
                sum[i]+=str2[m];
        for(v=2*j/3;v<j;v++)
            if(!strcmp(str[i],str[v]))
                sum[i]+=str2[v];
    }
    for(i=0;i<j/3;i++)
    {
        printf("%s %lf ",str[i],(float)str2[i]/sum[i]);
        for(m=j/3;m<2*j/3;m++)
            if(!strcmp(str[i],str[m]))
                printf("%lf ",(float)str2[m]/sum[i]);
        for(v=2*j/3;v<j;v++)
            if(!strcmp(str[i],str[v]))
                printf("%lf\n",(float)str2[v]/sum[i]);
    }
}

