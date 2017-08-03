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
#include <sstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 105
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
bool cmp(const string &a , const string &b);

int main()
{
    string ar[MAX];
    int t, r, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &r, &c);
        for(int i = 0 ; i < c ; ++i) cin >> ar[i];
        sort(ar , ar + c , cmp);
        for(int i = 0 ; i < c ; ++i) printf("%s\n",ar[i].c_str());
        if(t) printf("\n");
    }
    return 0;
}


bool cmp(const string &a , const string &b)
{
    int x = 0;
    int y = 0;
    for(int i = 0 ; a[i] ; ++i) for(int j = i + 1 ; b[j] ; ++j)
    {
        if(a[i] > a[j]) ++x;
        if(b[i] > b[j]) ++y;
    }
    if(x < y) return true;
    return false;
}

