#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

using namespace std;

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<20)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             65
#define MAXR            305
#define MAXC            305
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
int one[] = {-1 , 1 , 0 , 0};
int two[] = { 0 , 0 ,-1 , 1};

///***************************************  END  **********************************************///

map < int ,vector < int > > mp;
map < int , bool > root;
map < int , bool > ::iterator itt;
map < int ,vector < int > > ::iterator it;
int BFS(int temp);


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int a , b , head , cnt , cc = 0;
    while(sf("%d %d", &a , &b) && (a != -1 || b != -1))
    {
        if(!a && !b)
        {
            pf("Case %d is a tree.\n", ++cc);
            continue;
        }
        cnt = 0;
        mp[a].push_back(b);
        root[b] = true;
        root[a];
        while(sf("%d %d", &a , &b) && (a || b)) mp[a].push_back(b) , root[b] = true , root[a];
        for(it = mp.begin() ; it != mp.end() ; ++it) if(!root[it->fs])
        {
            head = it->fs;
            ++cnt;
        }
        if(cnt >= 2)
        {
            root.clear();
            mp.clear();
            pf("Case %d is not a tree.\n", ++cc);
            continue;
        }
        for(itt = root.begin() ; itt != root.end() ; ++itt) itt->se = false;
        head = BFS(head);
        if(head)
        {
            cnt = 0;
            for(itt = root.begin() ; itt != root.end() ; ++itt) if(!itt->se) ++cnt;
            if(!cnt) pf("Case %d is a tree.\n", ++cc);
            else pf("Case %d is not a tree.\n", ++cc);
        }
        else pf("Case %d is not a tree.\n", ++cc);
        root.clear();
        mp.clear();
    }
    return 0;
}


int BFS(int temp)
{
    root[temp] = true;
    queue < int > Q;
    Q.push(temp);
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        int len = mp[k].size();
        for(int i = 0 ; i < len ; ++i)
        {
            int l = mp[k][i];
            if(!root[l])
            {
                root[l] = true;
                Q.push(l);
            }
            else return 0;
        }
    }
    return 1;
}
