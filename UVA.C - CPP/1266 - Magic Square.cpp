#include <bits/stdc++.h>

#define sf scanf
#define pf printf

int ar[16][16];

int main()
{
    //freopen("output.txt" , "w" , stdout);
    int n , x , y , lim = 0;
    while( sf("%d" , &n) != EOF)
    {
        if(lim) pf("\n");
        pf("n=%d, sum=%d\n" , n , n * (n * n + 1) >> 1);
        memset(ar , 0 , sizeof(ar));
        x = 0 , y = n >> 1;
        lim = (n * n);
        for(int i = 1 ; i <= lim ; ++i)
        {
            if(ar[x][y])
            {
                x = x + 2; y--;
                if(x >= n) x = x - n;
                if(y < 0) y = y + n;
                ar[x][y] = i;
            }
            else ar[x][y] = i;
            x--; y++;
            if(x < 0) x = x + n;
            if(y >= n) y = y - n;
        }
        if(lim <= 9) for(int i = 0; i < n; i++, puts("")) for(int j = 0; j < n; j++) printf("%2d", ar[i][j]);
		else if(lim >= 10 && lim <= 100) for(int i = 0; i < n; i++, puts("")) for(int j = 0; j < n; j++) printf("%3d", ar[i][j]);
		else  for(int i = 0; i < n; i++, puts("")) for(int j = 0; j < n; j++) printf("%4d", ar[i][j]);
    }
    return 0;
}
