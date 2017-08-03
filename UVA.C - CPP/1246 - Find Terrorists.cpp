#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define sf scanf
#define pf printf
#define ab(a) (((a) > 0) ? (a) : -(a))

using namespace std;
vector < int > prime;
bool sive[10010];
bool save[10010];

void is_prime()
{
    int k = sqrt(10010);
    prime.push_back(2);
    for(int i = 3 ; i < k ; i = i + 2)
    {
        if(!sive[i]) for(int j = (i * i) ; j < 10010 ; j = j + (2 * i)) sive[j] = true;
    }
    for(int i = 3 ; i < 10010 ; i = i + 2) if(!sive[i]) prime.push_back(i);
}

bool is_factor(int num)
{
    int cnt , ans = 1;
    for(int i = 0 ; prime[i] <= num ; ++i)
    {
        if(num % prime[i] == 0)
        {
            cnt = 0;
            while(num % prime[i] == 0) { num = num / prime[i]; ++cnt; }
            ans = ans * (cnt + 1);
        }
    }
    if(num != 1) ans = ans * (cnt + 1);
    return binary_search(prime.begin() , prime.end() , ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    is_prime();
    for(int i = 2 ; i <= 10000 ; ++i) save[i] = is_factor(i);
    int t , a , b;
    cin >> t ;
    while(t--)
    {
        cin >> a >> b ;
        bool flag = false;
        for(int i = a ; i <= b ; ++i)
        {
            if(save[i])
            {
                if(!flag)
                {
                    cout << i ;
                    flag = true;
                }
                else cout << " " << i ;
            }
        }
        if(!flag) cout << -1 ;
        cout << endl;
    }
    return 0;
}
