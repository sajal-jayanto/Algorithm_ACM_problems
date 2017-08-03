#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 1100
int GCD(int,int);
char str[MAX];
int  num[MAX];

int main()
{
    int t,sum,k;
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        gets(str);
        sum = k = 0;
        for(int i = 0 ; str[i] != '\0' ; i++)
        {
            if(isdigit(str[i]) != 0)
            {
                sum = (sum * 10) + (str[i] - 48);
            }
            else if(sum != 0)
            {
                num[k++] = sum;
                sum = 0;
            }
        }
        if(sum != 0) num[k++] = sum;
        sum = 0;
        for(int i = 0 ; i < k ; i++)
        {
            for(int j = i + 1 ; j < k ; j++)
            {
               sum = sum > GCD(num[i] , num[j]) ? sum : GCD(num[i] ,num[j]);
            }
        }
        printf("%d\n",sum);
    }

   return 0;
}
int GCD(int i, int j)
{
    int x;
    while(i)
    {
        x = i;
        i = j % i;
        j = x;
    }
    return j;
}
