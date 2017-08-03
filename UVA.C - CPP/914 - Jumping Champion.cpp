#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX 1000010
void is_prime();
bool seev[MAX];
int prime[MAX];
int count[115];
int main()
{
    is_prime();
    int t,a,b,x,y,max,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        x = a < b ? a : b;
        y = a > b ? a : b;
        a = 0;
        for(int i = x ; i <= y ; i++)
        {
            if(seev[i] == false)
            {
                prime[a++] = i;
            }
        }
        if(a == 1)
        {
            printf("No jumping champion\n");
            continue;
        }
        max = 0;
        for(int i = 1 ; i < a ; i++)
        {
            b = prime[i] - prime[i - 1];
            count[b]++;
        }
        for(int i = 1 ; i < 115 ; i++)
        {
            if(max < count[i])
            {
                max = count[i];
                a = i;
            }
        }
        n = 0;
        for(int i = 1 ; i < 115 ; i++)
        {
            if(max == count[i]) n++;
            count[i] = 0;
        }
        if(n == 1)
        {
            printf("The jumping champion is %d",a);
        }
        else printf("No jumping champion");
        printf("\n");
    }
    return 0;
}

void is_prime()
{
    for(int i = 2 ; i < sqrt(MAX) ; i++)
    {
        if(i == 2 || seev[i] == false)
        {
            for(int j = i + i ; j < MAX ; j = j + i)
            {
                seev[j] = true;
            }
        }
    }
    seev[0] = seev[1] = true;
}

