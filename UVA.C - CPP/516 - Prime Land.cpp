#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 32780
#define MAXP 12737
#define MAXN 1000
void is_prime();
int factor(int);
int pow(int , int);
using namespace std;

bool sive[MAX];
int prime[MAXP];
char input[MAXN];
int num[MAXN];
struct ans
{
    int a;
    int b;

}ans[MAXN];

int main()
{
    //freopen("output.txt","w",stdout);
	char *p;
	is_prime();
	int n,k;
	long long sum;
	while(gets(input) && (strlen(input) != 1 || input[0] != '0'))
	{
		k = 0;
		sum = 1;
		p = strtok(input," ");
		while(p != NULL)
		{
			n = atoi(p);
			num[k++] = n;
			p = strtok(NULL," ");
		}
		for(int i = 0 ; i < k ; i = i + 2)
		{
			sum = sum  * (pow(num[i] , num[i + 1]));

		}
		sum = sum - 1;
        n = factor(sum);

        for(int i = n - 1 ; i > 0 ; i--)
        {
            printf("%d %d ",ans[i].a,ans[i].b);
        }
        printf("%d %d\n",ans[0].a,ans[0].b);
	}
	return 0;
}
int pow(int n , int p)
{
	if(p == 0) return 1;
	if(p % 2 == 0)
	{
		int temp = pow(n ,p/2);
		return temp * temp;
	}
	else return n * pow(n,p - 1);
}
int factor(int p)
{
	int n = sqrt(p);
	int count;
	int k = 0;
	for(int i = 0 ; prime[i] <= n ; i++)
	{
		if(p % prime[i] == 0)
		{
			count = 0;
			while(p % prime[i] == 0)
			{
				p = p / prime[i];
				count++;
			}
            ans[k].a = prime[i];
            ans[k].b = count;
            k++;
		}
	}
	if(p != 1)
	{
		ans[k].a = p;
        ans[k].b = 1;
        k++;
	}
	return k;
}
void is_prime()
{
	int k = 0;
	int n = sqrt(MAX);
	prime[k++] = 2;
	for(int i = 3 ; i < MAX ; i++)
	{
		if(sive[i] == false)
		{
			for(int j = i * i ; j < MAX ; j = j +(2 * i))
			{
				sive[j] = true;
			}
		}
	}
	for(int i = 3 ; i < MAX ; i++)
	{
		if(sive[i] == false) prime[k++] = i;
 	}
}
