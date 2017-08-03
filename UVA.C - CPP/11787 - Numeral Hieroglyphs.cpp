#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int valu(char);
bool code_error(char x[]);
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char ar[1000];
    int t;
    long long sum;
    scanf("%d",&t);
    gets(ar);
    while(t--)
    {
        gets(ar);
        if(code_error(ar) == 1) {printf("error\n");continue;}
        sum = 0;
        for(int i = 0 ; i < strlen(ar) ; i++)
        {
            sum = sum + valu(ar[i]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
int valu(char ch)
{

    if(ch == 'B') return 1;
    else if(ch == 'U') return 10;
    else if(ch == 'S') return 100;
    else if(ch == 'P') return 1000;
    else if(ch == 'F') return 10000;
    else if(ch == 'T') return 100000;
    else if(ch == 'M') return 1000000;
}
bool code_error(char x[])
{
    int B,U,S,P,F,T,M;
    B = U = S = P = F = T = M = 0;
    for(int i = 0 ; i < strlen(x) ; i++)
    {
        if(x[i] == 'B') B++;
        else if(x[i] == 'U') U++;
        else if(x[i] == 'S') S++;
        else if(x[i] == 'P') P++;
        else if(x[i] == 'F') F++;
        else if(x[i] == 'T') T++;
        else if(x[i] == 'M') M++;
        else return 1;
    }
    if(B <= 9 && U <= 9 && S <= 9 && P <= 9 && F <= 9 && T <= 9 && M <= 9);
    else return 1;
    for(int i = 0 ; i < strlen(x) - 1 ; i++)
    {
        if(valu(x[i]) >= valu(x[i + 1])) B = 0;
        else { B  = 1; break; }
    }
    for(int i = 0 ; i < strlen(x) - 1 ; i++)
    {
        if(valu(x[i]) <= valu(x[i + 1])) U = 0;
        else { U = 1; break; }
    }
    if((B == 0 && U == 1) || (B == 1 && U == 0)||(B == 0 && U == 0)) return 0;
    else return 1;
}


