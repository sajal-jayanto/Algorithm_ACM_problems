#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <string>
#define MAX 15

using namespace std;

long long Catalan(int n);
long long DP[MAX];


int main()
{
    memset(DP,-1, sizeof(DP));
    Catalan(12);
    int num,cnt = 0;
    while(scanf("%d",&num) == 1)
    {
        if(cnt != 0) printf("\n");
        printf("%lld\n",DP[num]);
        cnt++;
    }
    return 0;
}

long long Catalan(int n)
{
    if(n == 0) return 1;
    if(DP[n] != -1) return DP[n];

    int ans = 0;
    for(int i = 1 ; i<= n ; i++)
    {
        ans = ans + Catalan(i - 1) * Catalan(n - i);
    }
    return DP[n] = ans;
}
