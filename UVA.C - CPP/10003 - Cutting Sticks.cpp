#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int len , n ;
int num[56];
int DP[1010][1010];

int call(int left , int right)
{
    int &ret = DP[left][right];
    if(ret != -1)  return ret;
    ret = (1 << 20);
    for(int i = 0 ; i < n ; ++i)
    {
        if(num[i] > right ) break;
        if( (num[i] > left) && (num[i] < right) ) ret = min(ret , ( right - left ) + call(left , num[i]) + call(num[i] , right) );
    }
    if( ret == (1 << 20) ) ret = 0;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(false);
    while(cin >> len && len)
    {
        cin >> n ;
        for(int i = 0 ; i < n ; ++i) cin >> num[i];
        sort(num , num + n);
        memset(DP , -1 , sizeof(DP));
        cout << "The minimum cutting is " << call(0 , len) << "." << endl;
    }
    return 0;
}
