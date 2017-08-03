#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define inf 100000000

using namespace std;


int main()
{
//    freopen("input.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    int n , s , e , len ;
    while(sf("%d" , &n) && n)
    {
        s = 1; e = n / 4;
        if(n % 4) e++;
        len = e;
        e = (e * 4);
        pf("Printing order for %d pages:\n" , n);
        for(int i = 1 ; i <= len ; ++i)
        {
            pf("Sheet %d, front: " , i);
            if(e <= n) pf("%d," , e);
            else pf("Blank,");
            e--;
            pf(" %d\n" , s++);
            if(n == 1) continue ;
            pf("Sheet %d, back : " , i);
            pf("%d,", s++);
            if(e <= n) pf(" %d\n" , e);
            else pf(" Blank\n");
            e--;
        }
    }
    return 0;
}
