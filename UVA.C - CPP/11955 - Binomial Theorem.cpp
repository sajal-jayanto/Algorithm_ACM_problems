#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
long long nCr(int,int);
char ar[300];
char frist[100];
char second[100];
char third[20];
int main()
{
    //freopen("output.txt","w",stdout);
    int t,n,k,i,pow,count = 0;
    scanf("%d",&t);
    gets(ar);
    while(t--)
    {
        gets(ar);
        n = k = 0;
        for(i = 0 ; ar[i] ; i++)
        {
            n++;
            if(ar[i] == '+') break;
            if( islower(ar[i]) != 0 )frist[k++] = ar[i];
        }
        frist[k] = '\0';
        k = 0;
        for(i = n ; ar[i] ; i++)
        {
            n++;
            if(ar[i] == ')') break;
            if( islower(ar[i]) != 0 )second[k++] = ar[i];
        }
        second[k] = '\0';
        k = 0;
        for(i = n ; ar[i] ; i++)
        {
            if( isdigit(ar[i]) != 0 )third[k++] = ar[i];
        }
        third[k] = '\0';
        pow = atoi(third);
        printf("Case %d: ",++count);
        if(pow == 1)
        {
            printf("%s+%s\n",frist,second);
            continue;
        }
        printf("%s^%d",frist,pow);
        n = pow;
        for(i = 1 ; i < pow; i++)
        {
            n--;
            printf("+%lld*%s",nCr(pow,i),frist);
            if(n > 1) printf("^%d",n);
            printf("*");
            printf("%s",second);
            if(i > 1) printf("^%d",i);
        }
        printf("+%s^%d\n",second,pow);
    }
    return 0;
}

long long nCr(int n ,int r)
{
    int i;
    long long ans = 1;
    r = r < (n - r) ? r : (n - r);
    for(i = 1 ; i <= r ; i++)
    {
        ans = ans * (n - r + i);
        ans = ans / i;
    }
    return ans;
}
