#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 10010

using namespace std;

int phi[MAX];
long long ans[MAX];

int main()
{
//    freopen("input.txt" , "r" , stdin);
    for(int i = 1 ; i < MAX ; i++) phi[i] = i;
    for(int i = 2 ; i < MAX ; i++)
    {
        if(phi[i] != i) continue;
        for(int j = i ; j < MAX ; j = j + i) phi[j] = phi[j] / i * (i - 1);
    }
    for(int i = 1 ; i < MAX ; i++)
    {
        for(int j = 1 ; j < MAX ; ++j) ans[ (i < j) ? j : i ] += (phi[i] * phi[j]);
    }
    for(int i = 1 ; i < MAX ; i++) ans[i] += ans[i - 1];
    int t , temp ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &temp);
        pf("%lld\n" , ans[temp]);
    }
    return 0;
}
