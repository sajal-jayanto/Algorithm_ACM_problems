#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define pf printf
#define sf scanf

using namespace std;

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t , last , cnt , mx ;
    string str , s ;
    cin >> t;
    getline(cin , str);
    while(t--)
    {
        getline(cin , str);
        istringstream token(str);
        last = cnt = mx = 0;
        token >> s;
        last = s.size();
        while(token)
        {
            if(last == (int)s.size()) ++cnt;
            else
            {
                mx = max(mx , cnt);
                cnt = 1;
                last = (int) s.size();
            }
            token >> s;
        }

        mx = max(mx , cnt);

        cout << mx << endl;
    }
    return 0;
}