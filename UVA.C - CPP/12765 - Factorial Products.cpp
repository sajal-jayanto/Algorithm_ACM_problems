#include <bits/stdc++.h>

using namespace std;

#define sf  scanf
#define pf  printf

int call(int temp , int p)
{
    int cnt = 0;
    while(temp >= p)
    {
        cnt = cnt + (temp / p);
        temp = temp / p;
    }
    return cnt;
}

int main()
{
    int ar[10];
    int br[10];
    int n , m , temp ;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        memset(ar , 0 , sizeof(ar));
        memset(br , 0 , sizeof(br));
        while(n--)
        {
            sf("%d" , &temp);
            ar[2] = ar[2] + call(temp , 2);
            ar[3] = ar[3] + call(temp , 3);
            ar[5] = ar[5] + call(temp , 5);
            ar[7] = ar[7] + call(temp , 7);
        }
        while(m--)
        {
            sf("%d" , &temp);
            br[2] = br[2] + call(temp , 2);
            br[3] = br[3] + call(temp , 3);
            br[5] = br[5] + call(temp , 5);
            br[7] = br[7] + call(temp , 7);
        }
        bool flag = false;
        if(ar[2] != br[2]) flag = true;
        if(ar[3] != br[3]) flag = true;
        if(ar[5] != br[5]) flag = true;
        if(ar[7] != br[7]) flag = true;
        if(!flag) pf("YES\n");
        else pf("NO\n");
    }
    return 0;
}
