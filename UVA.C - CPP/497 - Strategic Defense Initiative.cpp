#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 100000
using namespace std;
int have[MAX];
int DP[MAX];
int LIS(int n);
void print_lis(int n , int p);

int main()
{
   // freopen("input.txt","r",stdin);
    char temp[20];
    int t,k;
    scanf("%d",&t);
    gets(temp);
    gets(temp);
    while(t--)
    {
        k = 0;
        while(gets(temp) && temp[0] != '\0'){  have[k++] = atoi(temp);}
        int p  = LIS(k);
        printf("Max hits: %d\n",p);
        print_lis(k, p);
        if(t) printf("\n");
    }
    return 0;
}


int LIS(int n )
{
    for(int i = 0 ; i < n  ; i++) DP[i] = 1;
    for(int i = 0 ; i < n ; i++)
        for(int j = i + 1 ; j < n ; j++)
            if((have[j] > have[i]) && (DP[j] < DP[i] + 1))
                DP[j] = DP[i] + 1;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
        cnt = max(cnt , DP[i]);

    return cnt;
}

void print_lis(int n , int p)
{
    int save[p + 2];
    int a = 0;
    for(int i = 1 ; i < n ; i++)
        if(DP[i] > DP[a]) a = i;

    int top = DP[a] - 1;
    save[top] = have[a];
    top--;
    for(int i = a - 1 ; i >= 0  ; i--)
        if((have[i] < have[a]) && ( DP[i] == DP[a] - 1))
            {a = i; save[top--] = have[a];}

    for(int i = 0 ; i < p ; i++) printf("%d\n",save[i]);
}

