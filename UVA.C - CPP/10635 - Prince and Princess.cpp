#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#define MAX 62508

using namespace std;
int A[MAX];
int B[MAX];
int DP[MAX];

int main()
{
    int t;
    int n,p,q,temp,cc = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&p,&q);

        p++;
        q++;
        memset(DP , 0, sizeof(DP));
        for(int i = 1 ; i <= p ; i++)
        {
            scanf("%d",&temp);
            DP[temp] = i;
        }
        for(int i = 1 ; i <= q ; i++)
        {
            scanf("%d",&temp);
            B[i] = DP[temp];
        }
        int cnt = 0;
        A[0] = 0;

        for(int i = 0 ; i <= q ; i++)
        {
            if(B[i] > A[cnt])
            {
                cnt++;
                A[cnt] = B[i];
            }
            else
            {
                int k = (int) (lower_bound(A, A + cnt + 1, B[i]) - A);
                if(B[i] > A[k]) k++;
                A[k] = B[i];
            }
        }
        printf("Case %d: %d\n",++cc,cnt);
    }
    return 0;
}
