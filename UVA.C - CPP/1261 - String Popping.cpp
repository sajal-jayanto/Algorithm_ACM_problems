#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


bool call(string temp)
{
    if(temp.empty()) return true;
    bool ret = false;
    for(int i = 0 ,  j ; i < temp.size() && !ret ; ++i)
    {
        for( j = i ; temp[i] == temp[j] && j < temp.size() ; ++j);
        if(j - i >= 2) ret = ret | call(temp.substr(0 , i) + temp.substr(j));
        i = j - 1;
    }
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false); cin.tie(false);
    int t;
    string str;
    cin >> t;
    while(t--)
    {
        cin >> str;
        cout << call(str) << endl;
    }
    return 0;
}
