#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 10000

using namespace std;

int num[MAX + 5];

int call(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    int &ret = num[n];
    if(ret != -1) return ret;
    ret = n;
    for(int i = 1 ; i * i <= n ; ++i) ret = min(ret , 1 + call(n - (i * i)));
    return ret;
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , temp ;
    memset(num , -1 , sizeof(num));
    sf("%d", &n) ;
    while(n--)
    {
        sf("%d" , &temp);
        pf("%d\n" , call(temp));
    }
    return 0;
}
