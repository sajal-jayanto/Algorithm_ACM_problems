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
#define MAX 10005
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
struct node{
    int a;
    int b;
};
node pos;
void dijistra(int t , int a);
map < int , vector < node > > mymap;
map < int , vector < int > > print;
vector < int > vec;


int main()
{
    int t , n , cc = 0;
    while(scanf("%d", &t) && t)
    {
        for(int i = 1 ; i <= t ; ++i)
        {
            scanf("%d", &n);
            while(n--)
            {
                scanf("%d %d", &pos.a , &pos.b);
                mymap[i].push_back(pos);
            }
        }
        scanf("%d %d" , &pos.a , &pos.b);
        dijistra(t , pos.a);
        print[pos.b].push_back(pos.b);
        int k = print[pos.b].size();
        printf("Case %d: Path =", ++cc);
        for(int i = 0 ; i < k ; ++i) printf(" %d", print[pos.b][i]);
        printf("; %d second delay\n", vec[pos.b]);
        mymap.clear();
        print.clear();
    }
    return 0;

}

void dijistra(int t , int a)
{
    vec.clear();
    for(int i = 0 ; i <= t ; ++i) vec.push_back(1000000000);
    vec[a] = 0;
    priority_queue < int > Q;
    Q.push(a);
    while(!Q.empty())
    {
        int k = Q.top();
        Q.pop();
        int len = mymap[k].size();
        for(int i = 0 ; i < len ; ++i)
        {
            int l = mymap[k][i].a;
            if(vec[l] > vec[k] + mymap[k][i].b)
            {
                vec[l] = vec[k] + mymap[k][i].b;
                print[l] = print[k];
                print[l].push_back(k);
                Q.push(l);
            }
        }
    }
}

