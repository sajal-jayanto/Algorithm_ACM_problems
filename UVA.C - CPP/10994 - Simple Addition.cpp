#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

long long sum(long long n)
{
    return ((n * (n + 1)) >> 1);
}

long long total(long long n)
{
    if(n == 0) return 0;
    if(n < 10) return sum(n);
    return total(n / 10LL) + (n / 10LL * 45LL) + sum(n % 10);
}

int main()
{
    long long a , b ;
    while(cin >> a >> b && (a != -1 || b != -1) )
    {
        cout << total(b) - total(a - 1) << endl;
    }
    return 0;
}
