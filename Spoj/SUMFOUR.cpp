#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int ar[4010][4];
int a[16000010];
int b[16000010];

int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t , temp , cnt ;
    long long ans = 0;
    sf("%d" , &t);
    for(int i = 0 ; i < t ; ++i)
    {
        sf("%d %d %d %d" , &ar[i][0] , &ar[i][1] , &ar[i][2] , &ar[i][3]);
    }
    int id = 0;
    for(int i = 0 ; i < t ; ++i)
    {
        for(int j = 0 ; j < t ; ++j)
        {
            a[id] = ar[i][0] + ar[j][1];
            b[id] = ar[i][2] + ar[j][3];
            id++;
        }
    }
    sort(a , a + id);
    sort(b , b + id);
    temp = id - 1;
    for(int i = 0 ; i < id ; ++i)
    {
        while(a[i] + b[temp] > 0)
        {
            temp--;
            if(temp < 0) break ;
        }
        if(temp < 0) break ;
        cnt = temp;
        while(cnt >= 0 && a[i] + b[cnt] == 0)
        {
            cnt--;
            ans++;
        }
    }
    pf("%lld\n" , ans);
    return 0;
}
