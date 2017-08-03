#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#define MAXF 45
void do_it();
int find_it(int);
long long  Fibonacci[MAXF];
bool bord[MAXF];

int main()
{
    do_it();
    int t,num,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        while(num)
        {
            n = find_it(num);
            num = num - Fibonacci[n];
            bord[n] = true;
        }
        n = MAXF;
        while(bord[n] == false) n--;
        for(int i = n ; i > 0 ; i--)
        {
            printf("%d",bord[i]);
            bord[i] = false;
        }
        printf("\n");
    }
    return 0;
}

int find_it(int num)
{

    for(int i = MAXF - 1 ; i > 0 ; i--)
    {
        if(num >= Fibonacci[i]) return i;
    }
}

void do_it()
{
    Fibonacci[1] = 1;
    Fibonacci[2] = 2;
    for(int i = 3 ; i < MAXF ; i++)
    {
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }
}



