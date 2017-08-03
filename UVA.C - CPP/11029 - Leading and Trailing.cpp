#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
long long Trailing(int,int,int);
void  Leading(int n , int p);
int main()
{
    int t;
    int num,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&num,&p);
        Leading(num,p);
        printf("%03lld\n",Trailing(num,p,1000));
    }
    return 0;

}
void Leading(int n , int p)
{

    double k = p * log10(n);
    k = k - floor(k);
    k = pow(10,k);
    k = k * 100.00;
    printf("%03d...",(int)k);

}

long long Trailing(int n, int p,int m)
{

    long long sum;
    if(p == 0) return 1;
    if(p % 2 == 0)
    {
        sum = Trailing(n , p/2 , m);
        return ((sum % m) *(sum % m))% m;
    }
    else return ((n % m) * (Trailing(n, p - 1,m))% m) % m;

}
