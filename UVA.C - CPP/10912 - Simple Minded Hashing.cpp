#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
int n , m ;
int DP[27][27][360];

int call(int pos , int last , int sum)
{
    if(pos >= n)
    {
        if(sum == m) return 1;
        return 0;
    }
    if(sum >= m) return 0;
    int &ret = DP[pos][last][sum];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = last + 1 ; i <= 26 ; ++i) ret = ret + call(pos + 1 , i , sum + i);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(false);
    int cc = 0;
    while(cin >> n >> m && (n || m))
    {
        cout << "Case " << ++cc << ": " ;
        if(n > 26 || m > 351) cout << "0" << endl;
        else
        {
            memset(DP , -1 , sizeof(DP));
            cout << call(0 , 0 , 0) << endl;
        }
    }
    return 0;
}
