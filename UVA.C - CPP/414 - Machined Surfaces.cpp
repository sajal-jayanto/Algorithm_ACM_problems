#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    vector < int > cnt;
    string str;
    int t, small , sum , n;
    while(scanf("%d", &t) && t)
    {
        getline(cin , str);
        while(t--)
        {
            getline(cin , str);
            cnt.push_back(count(str.begin() , str.end() , ' ' ));
        }
        n = cnt.size();
        sum = cnt[0];
        small = cnt[0];
        for(int i = 1; i < n ; i++)
        {
            sum = sum + cnt[i];
            small = min(small , cnt[i]);
        }
        sum = sum - (small * n);
        printf("%d\n", sum);
        cnt.clear();
    }
    return 0;
}
