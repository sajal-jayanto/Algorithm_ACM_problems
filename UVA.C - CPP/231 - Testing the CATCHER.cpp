#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MAX 32780

#define PI (2 *  acos(0.0))
#define eps 1e-7

using namespace std;

int ar[MAX];
int DP[MAX];
int LIS(int k);

int main()
{
    int k,cc = 0;
    while(true)
    {
        k = 0;
        for(int i = 0 ;  ; i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i] == -1) break;
            k++;
        }
        if(ar[0] == -1) break;
        if(cc != 0) printf("\n");
        reverse(ar , ar + k);
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++cc,LIS(k));
    }
    return 0;
}


int LIS(int k)
{
    DP[0] = -MAX;
    for(int i = 1 ; i <= k ; i++) DP[i] = MAX;
    int cnt = 0;
    for(int i = 0 ; i < k ; i++)
    {
        int low,high,mid;
        low = 0;
        high = cnt;
        while(low <= high)
        {
            mid = low + ((high - low) / 2);
            if(DP[mid] < ar[i]) low = mid + 1;
            else high = mid - 1;
        }
        DP[low] = ar[i];
        if(cnt < low) cnt = low;
    }
    return cnt;
}
