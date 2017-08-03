#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int main()
{
    //freopen("output.txt" , "w" , stdout);
    int n , m , cnt , cn ,  x , y , cc = 0;
    while( sf("%d %d" , &n , &m) && (n || m))
    {
        pf("Triangular Museum %d\n" , ++cc);
        cnt = n * m;
        cn = (n - 1) * 2 ;
        for(int i = 1 ; i <= m ; ++i)
        {
            x = 2;
            y = cn - 2;
            for(int j = 1 ; j <= n ; j++)
            {
                --cnt;
                for(int j = 1 ; j <= cnt ; ++j) pf(" ");
                if(j == 1)
                {
                    for(int k = 1 ; k <= i ; ++k)
                    {
                        pf("/\\");
                        if(k != i) { for(int l = 1 ; l <= cn  ; ++l) pf(" "); }
                    }
                }
                else if(j == n)
                {
                    for(int k = 1 ; k <= i ; ++k)
                    {
                        pf("/");
                        for(int l = 1 ; l <= cn ; ++l) pf("_");
                        pf("\\");
                    }
                }
                else
                {
                    for(int k = 1 ; k <= i  ; ++k)
                    {
                        pf("/");
                        for(int l = 1 ; l <= x ; ++l) pf(" ");
                        pf("\\");
                        if(k != i) for(int l = 1 ; l <= y ; ++l) pf(" ");
                    }
                    x = x + 2;
                    y = y - 2;
                }
                pf("\n");
            }
        }
        pf("\n");
    }
    return 0;
}
