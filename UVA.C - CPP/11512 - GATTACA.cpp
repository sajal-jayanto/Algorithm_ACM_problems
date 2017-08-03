#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define base 100007

struct node {
    unsigned long long h;
    string pos;
    node(){}
    node(unsigned long long a , string b) { h = a ; pos = b; }
    bool operator < (const node &t) const {
        if(t.h == h) return t.pos > pos;
        return t.h > h;
    }
};

node dp[10010];
string str , st ;
unsigned long long H[10010];
unsigned long long bord[10010];
int n , cc ;

unsigned long long get_hash(int s , int e)
{
    return bord[s] - bord[s + e] * H[e];
}

int can(int len , int l)
{
    for(int i = 0 ; i <= len - l ; ++i) dp[i] = node(get_hash(i , l), str.substr(i , l));
    sort(dp , dp + len - l + 1);
    int cnt = 0  , flag = -1;
    string pos = "Z";
    for(int i = 0 ; i <= len - l ; ++i)
    {
        if(!i || dp[i].h != dp[i - 1].h) cnt = 0;
        if(++cnt >= 2)
        {
            if(pos >= dp[i].pos)
            {
                cc = cnt;
                pos = dp[i].pos;
            }
            flag = 1;
        }
    }
    st = pos;
    return flag;
}


int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    int t  , len , low , high , mid , ans ;
    H[0] = 1;
    for(int i = 1 ; i < 10010 ; ++i) H[i] = (H[i - 1] * base);
    cin >> t ;
    while(t--)
    {
        cin >> str;
        len = str.size();
        bord[len] = 0;
        for(int i = len - 1 ; i >= 0 ; --i) bord[i] = bord[i + 1] * base + str[i];
        if(can(len , 1) == -1) cout << "No repetitions found!" << endl;
        else
        {
            low = 1 , high = len;
            while(low <= high)
            {
                mid = (low + high) >> 1;
                if(can(len , mid) != -1)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            can(len , ans);
            cout << st << " " << cc << endl;
        }
    }
    return 0;
}
