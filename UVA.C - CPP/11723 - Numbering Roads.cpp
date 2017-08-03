#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{

    int a,b,count = 0;
    while (scanf("%d %d",&a,&b) && a)
    {
        a = (a - 1) / b;
        if(a > 26) printf("Case %d: impossible\n",++count);
        else printf("Case %d: %d\n",++count,a);
    }
    return 0;
}
