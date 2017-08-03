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
#define MAX 1000000
#define PI (2 *  acos(0.0))
#define eps 1e-7

int scearch(int,int);

using namespace std;

int num[MAX];

int main()
{
	int n,q,r,s,count = 0;
	while(scanf("%d %d",&n,&q) && (n || q))
	{
		printf("CASE# %d:\n",++count);
		for(int i = 0 ; i < n ; i++) scanf("%d",&num[i]);
		sort(num , num + n);
		while(q--)
		{
			scanf("%d",&s);
			r = scearch(n,s);
			if(r == -1) printf("%d not found\n",s);
			else printf("%d found at %d\n",s,r + 1);
		}
	}	
	
	return 0;
	
}

int scearch(int siz, int kye)
{
	int low = 0;
	int high = siz - 1;
	int mid;
	int result = -1;
	
	while(low <= high)
	{
		mid = low + (high - low) / 2;
		if(num[mid] == kye)
		{
			result = mid;
			high = mid - 1;
		}
		else if(kye > num[mid]) low = mid + 1;
		else if(kye < num[mid]) high = mid - 1;
	}
	
	return result;
}

