#include <bits/stdc++.h>


using namespace std;

template < class T > T Abs(T x) { return x > 0 ? x : -x; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b); }
template < class T > inline T lcm(T a,T b) { if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b)); }
long long bit_set(long long k , int p) { return k = (k|(1 << p));}
long long re_set(long long k , int p) { return k = (k & ~(1 << p));}
template < class T > inline T sqr(T n) { return n * n; }

long long bigmod ( long long a, long long p, long long mod )
{
    long long res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}


bool even(int num)
{
    int k ;
    while(num)
    {
        k = num % 10;
        if(k == 0 || k == 2 || k == 4 || k == 6 || k == 8) return false;
        num = num / 10;
    }
    return true;
}

bool sive[10000010];
vector < int > prime;

void is_prime()
{
    int k = sqrt(10000010);
    prime.push_back(2);
    for(int i = 3 ; i <= k ; i = i + 2) if(!sive[i]) for(int j = i * i ; j < 10000010 ; j = j + (2 * i)) sive[j] = true;
    for(int i = 3 ; i < 10000010 ; i = i + 2) if(!sive[i] && even(i)) prime.push_back(i);
}

vector < int > ans ;

string next(string str)
{
    char ch = str[0];
    int len = str.size();
    for(int i = 1 ; i < len ; ++i) str[i - 1] = str[i];
    str[len - 1] = ch;
    return str;
}


int main()
{
    is_prime();
    string temp ;
    bool flag ;
    int num , l , len = prime.size();
    for(int i = 0 ; i < len ; ++i)
    {
        if(prime[i] >= 100)
        {
            temp = toString(prime[i]);
            flag = true;
            l = temp.size();
            for(int k = 0 ; k < l  ; ++k)
            {
                temp = next(temp);
                if(sive[ atoi(temp.c_str()) ])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(prime[i]);
        }
    }
    int a , b ;
    while(cin >> a && a != -1)
    {
        cin >> b ;
        if(a > b) swap(a , b);
        num = upper_bound(ans.begin() , ans.end() , b) - lower_bound(ans.begin() , ans.end() , a);
        if(num == 0) cout << "No Circular Primes." << endl;
        else if(num == 1) cout << num  << " Circular Prime." << endl;
        else cout << num << " Circular Primes." << endl;
    }
}
