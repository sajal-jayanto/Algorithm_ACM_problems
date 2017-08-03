#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


struct node {
    int amount , priz;
    node(){}
    node(int a, int b) { amount = a ; priz = b; }
};

vector < node > ve;
int DP[105];


int call(int num)
{
    if(num <= 0) return 0;
    int &ret = DP[num];
    if(ret != -1) return ret;
    ret = (1 << 30);
    for(int i = 0 ; i < ve.size() ; ++i) ret = min(ret , call(num - ve[i].amount) + ve[i].priz);
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int a , b , c, t, cc = 0;
    char *p , str[100000];
    while(sf("%d.%d %d" , &a , &b , &t) != EOF)
    {
        pf("Case %d:\n" , ++cc);
        memset(DP , -1 , sizeof(DP));
        ve.push_back(node(1 , (a * 100) + b));
        while(t--)
        {
            sf("%d %d.%d" , &c , &a , &b);
            ve.push_back(node(c , (a * 100) + b));
        }
        gets(str);
        gets(str);
        p = strtok(str , " ");
        while(p != NULL)
        {
            a = atoi(p);
            pf("Buy %d for $" , a);
            a = call(a);
            pf("%d.%02d\n" , a / 100 , a % 100);
            p = strtok(NULL , " ");
        }
        ve.clear();
    }
    return 0;
}
