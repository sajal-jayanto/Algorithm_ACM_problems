#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define MAX 10000

using namespace std;

vector < int > ve[105];
string str , take ;
int n , m , k , lim , cc = 0 ;
int DP[105][(1 << 8) + 5][(1 << 8) + 5];
int vis[105][(1 << 8) + 5][(1 << 8) + 5];

int call(int pos , int mark1 , int mark2)
{
    if(mark1 == lim && mark2 == lim) return 0;
    if(pos >= k)  return (1 << 20);
    int t1 = mark1 , t2 = mark2 , &ret = DP[pos][mark1][mark2];
    if(vis[pos][mark1][mark2] == cc) return ret;
    for(int i = 1 ; i < (int) ve[pos].size() ; ++i)
    {
        if((t1 & (1 << ve[pos][i])) == 0) t1 = (t1 | (1 << ve[pos][i]));
        else t2 = (t2 | (1 << ve[pos][i]));
    }
    ret = min(call(pos + 1 , mark1 , mark2) , call(pos + 1 , t1 , t2) + ve[pos][0]);
    vis[pos][mark1][mark2] = cc;
    return ret;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    int mark1 , mark2  , sum , temp  ;
    bool flag;
    while( cin >> n >> m >> k)
    {
        if(!n && !m && !k) break;
        getline(cin , str);

        lim = (1 << n) - 1;
        mark1 = mark2 = sum = 0;
        for(int i = 0 ; i < m ; ++i)
        {
            flag = true;
            getline(cin , str);
            istringstream iss(str);
            while(getline(iss , take , ' '))
            {
                temp = atoi(take.c_str());
                if(flag && temp)
                {
                    sum = sum + temp;
                    flag = false;
                }
                else if(temp)
                {
                    temp--;
                    if((mark1 & (1 << temp)) == 0) mark1 = (mark1 | (1 << temp));
                    else mark2 = (mark2 | (1 << temp));
                }
            }
        }
        for(int i = 0 ; i < k ; ++i)
        {
            getline(cin , str);
            istringstream iss (str);
            flag = true;
            ve[i].clear();
            while(getline(iss , take , ' '))
            {
                temp = atoi(take.c_str());
                if(flag && temp)
                {
                    ve[i].push_back(temp);
                    flag = false;
                }
                else if(temp) ve[i].push_back(temp - 1);
            }
        }
        ++cc;
        sum = sum + call(0 , mark1 , mark2);
        pf("%d\n" , sum);
    }
    return 0;
}
