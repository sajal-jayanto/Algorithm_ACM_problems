#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 1548578
void is_prime();
bool seev[MAX];

int main()
{
    is_prime();
    int t,num,count;
    while(scanf("%d",&t) != EOF)
    {
        count = 0;
        while(t--)
        {
            scanf("%d",&num);
            if(seev[num] == true) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}

void is_prime()
{
    int n = sqrt(MAX);
    seev[0] = seev[1] = false;
    for(int i = 2 ; i < n ; i++)
    {
        if(seev[i] == false)
        {
            for(int j = i + i ; j < MAX ; j = j + i)
            {
                seev[j] = true;
            }
        }
    }
    for(int i = 4 ; i < MAX ; i++)
    {
        if(seev[i] == true)
        {
            for(int j = i + i ; j < MAX ; j = j + i)
            {
                seev[j] = false;
            }
        }
    }
}
