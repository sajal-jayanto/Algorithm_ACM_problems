#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define MAX 1000000
int made(int);
int do_it(int,int,int);
int bord[MAX];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    int frist,second,num,mod,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&frist,&second,&num,&mod);
        mod = made(mod);
        r = do_it(frist,second,mod);
        if(r >= num)
        {
            printf("%d\n",bord[num]);
        }
        else printf("%d\n",bord[num % r]);
    }
    return 0;
}
int do_it(int f,int s,int m)
{
    int i;
    bord[0] = f % m;
    bord[1] = s % m;
    bord[2] = (f + s) % m;
    for(i = 3 ; ; i = i + 3)
    {
        bord[i] = (bord[i - 1] + bord[i - 2]) % m;
        bord[i + 1] = (bord[i] + bord[i - 1]) % m;
        bord[i + 2] = (bord[i + 1] + bord[i]) % m;
        if(bord[0] == bord[i] && bord[1]  == bord[i + 1] && bord[2] == bord[i + 2]) break;
    }
    return i;
}

int made(int n)
{
    if(n == 1) return 10;
    if(n == 2) return 100;
    if(n == 3) return 1000;
    if(n == 4) return 10000;
}
