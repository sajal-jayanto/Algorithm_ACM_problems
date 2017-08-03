#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

vector < string > ve;
vector < string > ans;
string str;
int pre[80];

int main()
{
   // freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    string temp;
    int t , k , len , le , cnt , mx ;
    while(cin >> t && t)
    {
        for(int i = 0 ; i < t ; ++i)
        {
            cin >> temp;
            ve.push_back(temp);
        }
        mx = 0;
        cin >> str;
        le = str.size();
        for(int i = 0 ; i < t ; ++i)
        {
            k = 0;
            len = ve[i].size();
            pre[1] = 0;
            for(int j = 2 ; j <= len ; ++j)
            {
                while(k > 0 && ve[i][k] != ve[i][j - 1]) k = pre[k];
                if(ve[i][k] == ve[i][j - 1]) ++k;
                pre[j] = k;
            }
            cnt = 0;
            k = 0;
            for(int j = 1 ; j <= le ; ++j)
            {
                while(k > 0 && str[j - 1] != ve[i][k]) k = pre[k];
                if(str[j - 1] == ve[i][k]) ++k;
                if(k == len) { ++cnt , k = pre[k]; }
            }
            if(mx <= cnt)
            {
                if(mx == cnt) ans.push_back(ve[i]);
                else
                {
                    ans.clear();
                    mx = cnt;
                    ans.push_back(ve[i]);
                }
            }
        }
        cout << mx << endl;
        for(auto x : ans) cout << x << endl;
        ans.clear();
        ve.clear();
    }
    return 0;
}
