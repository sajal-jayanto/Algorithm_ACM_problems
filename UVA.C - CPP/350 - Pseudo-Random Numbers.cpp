#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 9999
int main()
{
    int Z,I,M,L,n,count,k = 0;
    long long sum;
    bool ar[MAX];
    while(scanf("%d %d %d %d",&Z,&I,&M,&L) == 4)
    {
        if(Z == 0 && I == 0 && M == 0 && L == 0) break;
        count = 0;
        for(int i = 0 ; i < M ; i++) ar[i] = 0;
        ar[L] = 1;n = L;
        while(1)
        {
            count++;
            sum = (Z * L) + I;
            L = sum % M;
            if(ar[L] == 1) break;
            else ar[L] = 1;
        }
        if(n != L) count--;
        printf("Case %d: %d\n",++k,count);
    }
    return 0;
}
