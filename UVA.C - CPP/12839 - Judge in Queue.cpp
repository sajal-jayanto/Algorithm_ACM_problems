#include <bits/stdc++.h>

using namespace std;

#define sf  scanf
#define pf  printf

struct node {

    long long total ;
    int indx ;
    node(long long a , int b) {  total = a; indx = b; }
    bool operator < (const node &t) const {
            return total > t.total ;
    }
};

long long cost[100010];
long long need[10010];
priority_queue < node > Q;

int main()
{
   // freopen("tem.txt" , "r" , stdin);
    int t , n , m , cc = 0;
    long long ans ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &m);
        for(int i = 0 ; i < n ; ++i) sf("%lld" , &cost[i]);
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%lld" , &need[i]);
            Q.push(node(0 , i));
        }
        sort(cost , cost + n);
        ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            node temp = Q.top();
            Q.pop();
            ans = max(ans , temp.total + cost[i]);
            temp.total = temp.total + need[temp.indx];
            Q.push(temp);
        }
        pf("Case %d: %lld\n" , ++cc , ans);
        while(!Q.empty()) Q.pop();
    }
    return 0;
}
