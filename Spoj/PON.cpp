#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

typedef unsigned long long llu;

llu mulmod(llu  a, llu  b, llu  mod)
{
    llu  x = 0 , y = a % mod;
    while (b > 0)
    {
        if (b & 1) x = (x + y) % mod;
        y = (y << 1) % mod;
        b = b >> 1;
    }
    return x % mod;
}

llu modulo(llu  base, llu  exponent, llu  mod)
{
    llu  x = 1;
    llu  y = base;
    while (exponent > 0)
    {
        if (exponent & 1) x = mulmod(x , y , mod) ;
        y = mulmod(y ,  y , mod) ;
        exponent = exponent >> 1;
    }
    return x % mod;
}

bool Miller(llu p)
{
    if (p < 2) return false;
    if (p != 2 && !(p & 1)) return false;
    llu  s = p - 1;
    while (!(s & 1)) s = s >> 1;
    for (int i = 0; i < 5 ; i++)
    {
        llu  a = rand() % (p - 1) + 1 , temp = s;
        llu  mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp = temp << 1;
        }
        if (mod != p - 1 && !(temp & 1)) return false;
    }
    return true;
}

int main()
{
	int t;
	llu num;
	sf("%d" , &t);
	while(t--)
	{
        sf("%llu" , &num);
        if(Miller(num)) pf("YES\n");
        else pf("NO\n");
	}
	return 0;
}
