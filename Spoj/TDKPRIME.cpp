#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 87000000

using namespace std;

bool sive[MAX + 2];
int prime[5100000];

int main()
{
    int cnt = 0;
    prime[++cnt] = 2;
    int k = sqrt(MAX);
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = (i * i) ; j < MAX ; j = j + (2 * i)) sive[j] = true;
    }
    for(int i = 3 ; i < MAX ; i = i + 2) if(!sive[i]) prime[++cnt] = i;
    int t , temp ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &temp);
        pf("%d\n" , prime[temp]);
    }
    return 0;
}
