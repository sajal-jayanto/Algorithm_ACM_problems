#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef deque < int > BigInt;

void Print(BigInt a) {
    for(int i = a.size() - 1 ; i >= 0 ; --i) pf("%d" , a[i]);
}

BigInt Integer(char *s , int cnt) {
    BigInt ans;
    if ( cnt == 0 ) { ans.push_back(0); return ans; }
    while (cnt % 9 != 0) { s[cnt++] ='0' ; }
    reverse(s , s + cnt);
    for (int i = 0  ; i < cnt ; i += 9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.push_front(v);
    }
    return ans;
}

BigInt Integer(int x) {
    char s[30];
    int cnt = 0;
    while (x)
    {
        s[cnt++] = (x % 10) + '0' ;
        x = x / 10;
    }
    s[cnt] = NULL;
    return Integer(s , cnt);
}

BigInt operator + (BigInt a, BigInt b) {
    BigInt ans;
    int carry = 0;
    FOR(i,0,max(a.size(), b.size())-1) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.push_back(carry % base);
        carry /= base;
    }
    if (carry) ans.push_back(carry);
    return ans;
}

int num[65];
BigInt dp[65][2][65];
bool vis[65][2][65];

BigInt call(int pos , int last , int cnt , int flag)
{
    if(pos == 0) return Integer(cnt);
    if(!flag && vis[pos][last][cnt]) return dp[pos][last][cnt];
    int n = flag ? num[pos] : 1;
    BigInt ans = Integer(0);
    for(int i = 0 ; i <= n ; ++i) ans = ans + call(pos - 1 , i , cnt + (last && i) , flag && (i == n));
    if(!flag)
    {
         vis[pos][last][cnt] = true;
         dp[pos][last][cnt] = ans;
    }
    return ans ;
}

BigInt pro(long long n)
{
    int len = 0;
    while(n)
    {
        num[++len] = n % 2;
        n = n / 2;
    }
    return call(len , 0 , 0 , 1);
}

int main()
{
  //  freopen("input.txt" , "r" , stdin);
    long long n ;
    int cc = 0;
    while(sf("%lld" , &n) && n != -1)
    {
        pf("Case %d: " , ++cc );
        Print(pro(n));
        pf("\n");
    }
    return 0;
}
