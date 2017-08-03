/*
	problem number : 
	problem name :
	algorithm :
	solve date :
*/
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

#define PI (2 *  acos(0.0))
#define eps 1e-7


using namespace std;

int main()
{
	long long t,num,count = 0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&num);
		num = num * (num - 1);
		if(num % 4 == 0) printf("Case %lld: %lld\n",++count,num / 4);
		else printf("Case %lld: %lld/2\n",++count,num / 2);
	}
	return 0;
}