#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define MAX 47
void Fibonacci();
int find_Fibonacci(long long);
long long ar[MAX];
int main()
{
    //freopen("output.txt","w",stdout);
    Fibonacci();
    int t,n,len,k;
    char word[110],print[110],an[110];
    long long get[110];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        len = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%lld ",&get[i]);
            if(len < get[i]) len = get[i];
        }
        gets(word);
        k = 0;
        for(int i = 0 ; i < strlen(word) ; i++)
        {
            if(isupper(word[i]) != 0)
            {
                an[k++] = word[i];
            }
        }
        an[k] = '\0';
        len = find_Fibonacci(len);
        for(int i = 0 ; i < len ; i++)
        {
            print[i] = ' ';
        }
        print[len] = '\0';
        for(int i = 0 ; i < n ; i++)
        {
            len = find_Fibonacci(get[i]);
            print[len - 1] = an[i];
        }
        printf("%s\n",print);
    }
    return 0;
}
void Fibonacci()
{
    ar[0] = 1;
    ar[1] = 1;
    for(int i = 2 ; i < MAX ; i++)
    {
        ar[i] = ar[i - 1] + ar[i - 2];
    }
}
int find_Fibonacci(long long num)
{
    for(int i = 1 ; i < MAX ; i++)
    {
        if(num == ar[i]) return i;
    }
}
