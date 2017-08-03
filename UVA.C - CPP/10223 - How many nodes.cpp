#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#define MAX 25

using namespace std;

long long Catalan(int n);
long long DP[MAX];
map < long long , int > mymap;

int main()
{
   // freopen("output.txt","w",stdout);
    memset(DP,-1,sizeof(DP));
    Catalan(21);
    long long num;
    while(scanf("%lld",&num) == 1)
    {
        if(mymap[num] != 0) printf("%d\n",mymap[num]);
    }
    return 0;

}

long long Catalan(int n)
{
    if(n == 0) return 1;
    if(DP[n] != -1) return DP[n];

    long long ans = 0;
    for(int i = 1 ; i<= n ; i++)
    {
        ans = ans + Catalan(i - 1) * Catalan(n - i);
    }
    DP[n] = ans;
    mymap[ans] = n;
    return DP[n];
}
