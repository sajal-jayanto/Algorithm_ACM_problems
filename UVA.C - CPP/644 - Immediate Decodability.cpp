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
#define INF             (1<<30)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             10010
#define MAXR            17
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
const double PI = 2.0 * acos(0.0);

struct node{

    node *next[2 + 1];
    node()
    {
        for(int i = 0 ; i < 2 ; ++i) next[i] = NULL;
    }
}*root;

void insert(string str , int len)
{
    node *p = root;
    for(int i = 0 ; i < len ; ++i)
    {
        int l = str[i] - '0';
        if(p->next[l] == NULL) p->next[l] = new node();
        p = p->next[l];
    }
}

bool search(string str , int len)
{
    node *p = root;
    for(int i = 0 ; i < len ; ++i)
    {
        int l = str[i] - '0';
        if(p->next[l] == NULL) return false;
        p = p->next[l];
    }
    for(int i = 0 ; i < 2 ; ++i) if(p->next[i] != NULL) return true;
    return false;
}

void del(node *p)
{
    for(int i = 0 ; i < 2 ; ++i)
    {
        if(p->next[i]) del(p->next[i]);
    }
    delete(p);
}

vector < string > ve;

int main()
{

    int t , cc = 0;
    bool flag;
    string st;
    while(cin >> st && st != "9")
    {
        root = new node();
        ve.push_back(st);
        insert(st , st.length());
        while(cin >> st && st != "9")
        {
            ve.push_back(st);
            insert(st , st.length());
        }
        flag = false;
        for(int i = 0 ; i < ve.size() ; ++i)
        {
            if(search(ve[i] , ve[i].length()))
            {
                flag = true;
                break;
            }
        }
        if(flag) pf("Set %d is not immediately decodable\n", ++cc);
        else pf("Set %d is immediately decodable\n", ++cc);
        del(root);
        ve.clear();
    }
    return 0;
}
