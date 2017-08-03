#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;
int DP[800][180][80];
int vis[800][180][80];
int cc = 0;

int call(int need , int one , int five , int ten)
{
    if(!need) return 0;
    int &ret = DP[one][five][ten];
    if(vis[one][five][ten] == cc) return ret;
    ret = (1 << 30);
    if(one >= 8)  ret = min(ret , 8 + call(need - 1 , one - 8 , five , ten));
    if(five >= 2) ret = min(ret , 2 + call(need - 1 , one + 2 , five - 2 , ten));
    if(one >= 3 && five >= 1) ret = min(ret , 4 + call(need - 1 , one - 3 , five - 1 , ten));
    if(ten >= 1)  ret = min(ret , 1 + call(need - 1 , one + 2 , five , ten - 1));
    if(one >= 3 && ten >= 1) ret = min(ret , 4 + call(need - 1 , one - 3 , five + 1 , ten - 1));
    vis[one][five][ten] = cc;
    return ret;
}

int main()
{
    int t , n , one , five , ten;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d %d %d" , &n , &one , &five , &ten);
        ++cc;
        pf("%d\n" , call(n , one , five , ten) );
    }
    return 0;
}
