#include <bits/stdc++.h>

using namespace std;

#define sf         scanf
#define pf         printf
#define fr         first
#define se         second
#define PI         (2 *  acos(0.0))
#define eps        1e-7
#define mem(a,b)   memset(a, b, sizeof(a))
#define ios        ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false)

struct point {
    int x , y ;
    point(){}
    point(int a , int b) { x = a ; y = b; }
};

vector < point > ve;
char str[30][30];
int cost[30][30];
int first[20];
int second[20][20];
int n , m ;
int one[] = {1 , 0 , -1 ,  0 };
int two[] = {0 , 1 ,  0 , -1 };

void bfs(int a , int b)
{
    mem(cost , -1);
    cost[a][b] = 0;
    queue < int > Q;
    Q.push(a) ; Q.push(b);
    int x , y , p , q  ;
    while(!Q.empty())
    {
        p = Q.front(); Q.pop();
        q = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; ++i)
        {
            x = p + one[i];
            y = q + two[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && cost[x][y] == -1 && str[x][y] != 'x')
            {
                cost[x][y] = cost[p][q] + 1;
                Q.push(x); Q.push(y);
            }
        }
    }
}


int main()
{
   // freopen("tem.txt" , "r" , stdin);
    int temp , len , ans ;
    point me ;
    while( sf("%d %d" , &m , &n) && (n || m))
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            for(int j = 1 ; j <= m ; ++j)
            {
                sf(" %c" , &str[i][j]);
                if(str[i][j] == 'o') me = point(i , j);
                if(str[i][j] == '*') ve.push_back(point(i , j));
            }
        }
        len = ve.size();
        bfs(me.x , me.y);
        for(int i = 0 ; i < len ; ++i) first[i] = cost[ve[i].x][ve[i].y];
        for(int i = 0 ; i < len ; ++i)
        {
            bfs(ve[i].x , ve[i].y);
            for(int j = 0 ; j < len ; ++j) second[i][j] = cost[ve[j].x][ve[j].y];
        }
        ans = (1 << 30);
        int ar[] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
        bool flag , can = false;
        do
        {
            flag = true ;
            temp = first[ar[0]];
            if(temp != -1)
            {
                for(int i = 1 ; i < len ; ++i)
                {
                    if(second[ar[i - 1]][ar[i]] == -1) flag = false ;
                    else temp = temp +  second[ar[i - 1]][ar[i]];
                }
            }
            else flag = false;
            if(flag)
            {
                can = true;
                ans = min(ans , temp);
            }
        }
        while(next_permutation(ar , ar + len));

        if(can) pf("%d\n" , ans);
        else pf("-1\n");
        ve.clear();
    }
    return 0;
}
