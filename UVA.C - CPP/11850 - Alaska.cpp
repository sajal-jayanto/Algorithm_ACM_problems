#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#define MAX 1422
#define MAXD 200
using namespace std;

int run[MAX];

int main()
{
    int t,n;
    bool flage;
    while(scanf("%d",&t) && t)
    {
        flage = true;
        for(int i = 0 ; i < t ; i++) scanf("%d",&run[i]);
        sort(run , run + t);
        for(int i = 1 ; i < t ; i++)
        {
            n = run[i] - run[i - 1];
            if(n > MAXD) flage = false;
        }
        n = (MAX - run[t - 1]) * 2;
        if(n > MAXD) flage = false;

        if(flage == true)  printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
