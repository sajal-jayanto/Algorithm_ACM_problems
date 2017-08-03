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
#define MAX             105
#define MAXR            305
#define MAXC            305
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
int one[] = {-1 , 1 , 0 , 0};
int two[] = { 0 , 0 ,-1 , 1};

///***************************************  END  **********************************************///

string post;
int search(char *temp , char ch , int len);
void post_oder(char *pre , char *in , int len);


int main()
{
   // freopen("input.txt" , "r" , stdin);
    char pre[MAX] , in[MAX];
    int t , len ;
    sf("%d", &t);
    while(t--)
    {
        sf("%d %s %s", &len , pre , in);
        post_oder(pre , in , len);
        pf("%s\n", post.c_str());
        post.clear();
    }
    return 0;
}

int search(char *temp , char ch , int len)
{
    for(int i = 0 ; i < len ; ++i) if(temp[i] == ch) return i;
    return -1;
}

void post_oder(char *pre , char *in , int len)
{

    int root = search(in , pre[0] , len);
    if(root) post_oder(pre + 1 , in , root);
    if(root != len - 1) post_oder(pre + root + 1 , in + root + 1 , len - root - 1);
    post = post + pre[0];
}
