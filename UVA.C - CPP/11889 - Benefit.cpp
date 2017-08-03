#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int GCD(int,int);
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,a,c,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&c);
        if(c % a != 0)
        {
            printf("NO SOLUTION\n");
        }
        else
        {
            n = c / a;
            for(int i = n ; i <= c ; i = i + n)
            {
                if(a / GCD(a,i) * i == c)
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
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
