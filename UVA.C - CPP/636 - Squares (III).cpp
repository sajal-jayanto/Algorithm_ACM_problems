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


using namespace std;


int main()
{
	char num[15];
	int len,max,p;
	long long sum;

	while(scanf("%s",num) == 1)
	{
		len = strlen(num);
		if(len == 1 && num[0] == '0') break;
		max = 0;
		for(int i = 0 ; i < len ; i++)
		{
			num[i] = num[i] - 48;
			if(max < num[i]) max = num[i];
		}
		
		max = max + 1;
		
		for(int i = max ; i <= 100 ; i++)
		{
			sum = 0;
			p = 1;
			for(int j = len - 1 ; j >= 0 ; j--)
			{
				sum = sum + num[j] * p;
				p = p * i;
			}
			if(sqrt(sum) == floor(sqrt(sum)))
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}