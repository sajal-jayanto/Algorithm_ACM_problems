#include <bits/stdc++.h>

using namespace std;

#define sf         scanf
#define pf         printf

long long nCr(long long N , long long R)
{
    if(R > N - R) R = N - R;
	long long ans = 1;
	for(long long i = 1 ; i <= R ; i++)
	{
		ans = ans * (N - i + 1);
		ans = ans / i;
	}
	return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    long long n , k ;
    int t;
    cin >> t ;
    while(t--)
    {
        cin >> n >> k ;
        if(n == k)
        {
            cout << 1 << endl;
            continue;
        }
        else cout << nCr(n - 1 , k - 1) << endl;
    }
    return 0;
}
