#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define MAX 46350
#define MAXP 4793
#define MAXS 1000010
#define MAXSP 500000
void is_prime();
bool find_it(long long);
bool seev[MAX];
bool subseev[MAXS];
int prime[MAXP];
int subprime[MAXSP];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    is_prime();
    long long low,high,n,max,min,l1,l2,h1,h2,l;
    while(scanf("%lld %lld",&low,&high) == 2)
    {
        for(long long i = low ; i <= high ; i++)
        {
            if(find_it(i) == true)
            {
                subseev[i - low] = true;
            }
            else
            {
                subseev[i - low] = false;
                for(long long j = i + i; j <= high ; j = j + i)
                {
                    subseev[j - low] = true;
                }
            }
        }
        n = 0;
        for(int i = 0 ; i <= high - low ; i++)
        {
            if(subseev[i] == false) subprime[n++] = i + low;
            subseev[i] = false;
        }
        if(n == 1)
        {
            printf("There are no adjacent primes.\n");
            continue;
        }
        max = (subprime[1] - subprime[0]);
        min = (subprime[1] - subprime[0]);
        l1 = h1 = subprime[0];
        l2 = h2 = subprime[1];
        for(int i = 1 ; i < n ; i++)
        {
            l = (subprime[i] - subprime[i - 1]);
            if(max < l)
            {
                max = l;
                h1 = subprime[i - 1];
                h2 = subprime[i];
            }
            if(min > l)
            {
                min = l;
                l1 = subprime[i - 1];;
                l2 = subprime[i];
            }
        }
       printf("%lld,%lld are closest, %lld,%lld are most distant.\n",l1,l2,h1,h2);
    }
    return 0;
}

void is_prime()
{
    int k = 0;
    prime[k++] = 2 ;
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i = i + 2)
    {
        if(seev[i] == false)
        {
            for(int j = i * i ; j < MAX ; j = j + (2 * i))
            {
                seev[j] = true;
            }
        }
    }

    for(int i = 3 ; i < MAX ; i = i + 2)
    {
        if(seev[i] == false) prime[k++] = i;
    }
}

bool find_it(long long num)
{
    if(num < MAX)
    {
        if(num % 2 == 0 && num != 2 || num == 1) return true;
        else if(seev[num] == false) return false;
        else return true;
    }
    long long n = sqrt(num);
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0) return true;
    }
    return false;
}
