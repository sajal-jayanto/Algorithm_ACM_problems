#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

string give[52];
string dp[52][52];
int vis[52][52] , cc = 0;

string call(int s , int e)
{
    if(s == e) return "";
    string temp , &ret = dp[s][e];
    if(vis[s][e] == cc) return ret;
    for(int i = s + 1 ; i < e ; ++i)
    {
        for(int j = e - 1 ; j >= i ; --j)
        {
            if(give[s][i] == give[e][j])
            {
                temp = give[s][i] + call(i , j) + give[e][j];
                if(temp.size() >= ret.size())
                {
                    if(temp.size() == ret.size()) ret = min(temp , ret);
                    else ret = temp;
                }
            }
        }
    }
    vis[s][e] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    int t , n ;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0 ; i < n ; ++i)
        {
             cin >> give[i];
             for(int j = i + 1 ; j < n ; ++j) dp[i][j] = give[i][j];
        }
        ++cc;
        cout << call(0 , n - 1) << endl;
    }
    return 0;
}
