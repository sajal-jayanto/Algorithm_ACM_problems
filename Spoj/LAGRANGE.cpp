#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

int cnt[(1 << 15) + 2];
int ve[185];

int main()
{
  //  freopen("input.txt" , "r" , stdin );
    int t , temp , lim = (1 << 15) ;

    for(int i = 1 ; i < 185 ; ++i) ve[i] = (i * i);

    for(int i = 0 ; (ve[i] * 4) < lim ; ++i)
        for(int j = i ; ve[i] + (3 * ve[j]) < lim ; ++j)
            for(int k = j ; ve[i] + ve[j] + (2 * ve[k]) < lim ; ++k)
                for(int l = k ; ve[i] + ve[j] + ve[k] + ve[l] < lim ; ++l)
                    cnt[ve[i] + ve[j] + ve[k] + ve[l]]++;

    while(sf("%d" , &temp) && temp) pf("%d\n" , cnt[temp]);
    
    return 0;
}