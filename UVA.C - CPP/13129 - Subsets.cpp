#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 100000

void io()
{
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
}

long long p , ar[500010];
long long seg[(4 * 500010)];
const long long mod = 1000000007ll;

long long big_mod(long long num , long long p)
{
	if(p == 0) return 1;
	long long temp ;
	if(p & 1)
	{
		temp = big_mod(num , p - 1);
		return (num * temp) % mod;
	}
	temp = big_mod(num , p / 2);
	return (temp * temp) % mod;
}

void insert(int node , int beg , int end)
{
	if(beg == end)
	{
		seg[node] = big_mod(p , ar[beg]);
		return ;
	}
	int left , right , mid;
	left = node << 1;
	right = left + 1;
	mid = (beg + end) >> 1;
	insert(left , beg , mid);
	insert(right , mid + 1 , end);
	seg[node] = (seg[left] + seg[right] + (seg[left] * seg[right]) % mod) % mod;
}


long long query(int node , int beg , int end , int s , int e)
{
	if(beg == s && end == e) return seg[node] % mod;
	int left , right , mid;
	left = node << 1;
	right = left + 1;
	mid = (beg + end) >> 1;
	if(e <= mid) return query(left , beg , mid , s , e);
	else if(s > mid) return query(right , mid + 1 , end , s , e);
	else 
	{
		long long a = query(left , beg , mid , s , mid);
		long long b = query(right , mid + 1 , end , mid + 1 , e);
		return (a + b + (a * b) % mod) % mod;
	}
}


int main()
{
	//io();
	int n , m , x , y;
	long long ans ;
	while( sf("%d %lld" , &n , &p) == 2) 
	{
		for(int i = 1 ; i <= n ; ++i) sf("%lld" , &ar[i]);
		insert(1 , 1 , n);
		sf("%d" , &m);
		while(m--)
		{
			sf("%d %d" , &x , &y);
			ans = query(1 , 1 , n , x , y);
			pf("%lld\n" , ans);
		}
	}
	return 0;
}