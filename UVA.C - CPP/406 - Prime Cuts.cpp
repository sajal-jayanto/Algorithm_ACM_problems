#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1001
#define MAXP 500
void is_prime();
bool seev[MAX];
int prime[MAXP];

int main()
{
    is_prime();
    int a,b,k,n;
    while(scanf("%d %d",&a,&b) == 2)
    {
        printf("%d %d:",a,b);
        prime[0] = 1;
        k = 1;
        for(int i = 2 ; i <= a ; i++)
        {
            if(seev[i] == false)
            {
                prime[k++] = i;
            }
        }
        if(k % 2 == 0) b = b * 2;
        else b = (b * 2) - 1;
        n = k - b;
        n = n / 2;
        if(k >= b)
        {
            for(int i = n ; i < n + b ; i++)
                printf(" %d",prime[i]);
            printf("\n\n");
        }
        else
        {
            for(int i = 0 ; i < k  ; i++)
                printf(" %d",prime[i]);
            printf("\n\n");
        }
    }
    return 0;
}

void is_prime()
{
    int n = sqrt(MAX);
    for(int i = 2 ; i <= n ; i++)
    {
        if(seev[i] == false)
        {
            for(int j = i + i ; j <= MAX ; j = j + i)
            {
                seev[j] = true;
            }
        }
    }
    seev[0] = true;
}
