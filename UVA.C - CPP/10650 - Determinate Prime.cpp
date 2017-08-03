#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define MAX 32010
#define MAXP 3435
#define MAXN 162
void is_prime();
bool seev[MAX];
int prime[MAXP];
int ans[MAXN][4];

int main()
{
    is_prime();
    int a,b,x,y;
    while(scanf("%d %d",&a,&b) && (a || b))
    {
        x = a < b ? a : b;
        y = a > b ? a : b;
        for(int i = 0 ; i < MAXN ; i++)
        {
            if(x <=  ans[i][0] && y >= ans[i][3])
            {
                if(ans[i][2] == ans[i][3])
                {
                   printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
                }
                else printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
            }
        }
    }
    return 0;
}

void is_prime()
{

    int k = 0,a,b,c, x;
    bool flage;
    prime[k++] = 2;
    for(int i = 3 ; i < sqrt(MAX) ; i = i + 2)
    {
        if(seev[i] == false )
        {
            for(int j = i * i  ; j < MAX ; j = j + (2 * i))
            {
                seev[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAX ;  i = i + 2)
    {
        if(seev[i] == false)
        {
            prime[k++] = i;
        }
    }
    flage = false;
    x = 0;
    for(int i = 0 ; i <  k ; i++)
    {
        a = prime[i + 3] - prime[i + 2];
        b = prime[i + 2] - prime[i + 1];
        c = prime[i + 1] - prime[i];
        if(a == b  && a == c)
        {
            ans[x][0] = prime[i];
            ans[x][1] = prime[i + 1];
            ans[x][2] = prime[i + 2];
            ans[x][3] = prime[i + 3];
            flage = true;
            x++;
            continue;
        }
        if(b == c)
        {
            if(flage == true)
            {
                flage = false;
                continue;
            }
            ans[x][0] = prime[i];
            ans[x][1] = prime[i + 1];
            ans[x][2] = prime[i + 2];
            ans[x][3] = prime[i + 2];
            x++;
        }
    }
}

