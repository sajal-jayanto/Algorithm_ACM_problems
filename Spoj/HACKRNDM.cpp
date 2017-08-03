#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 10010

using namespace std;

unordered_map < int , int > mp;
unordered_map < int , int > ::iterator it ;

int ar[100010];

int main()
{
    int n , k , temp ;
    sf("%d %d" , &n , &k);
    for(int i = 0 ; i < n ; ++i)
    {
        sf("%d" , &ar[i]);
        mp[ar[i]]++;
    }
    int ans = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        temp = ar[i] + k;
        it = mp.find(temp);
        if(it != mp.end()) ans = ans + it->second;
    }
    pf("%d\n" , ans);
    return 0;
}
