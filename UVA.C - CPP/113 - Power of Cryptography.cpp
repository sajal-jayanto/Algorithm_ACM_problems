#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    double n,p;
    while(scanf("%lf %lf",&n,&p) == 2)
    {
        printf("%0.lf\n",pow(p,1/n));
    }
    return 0;
}
