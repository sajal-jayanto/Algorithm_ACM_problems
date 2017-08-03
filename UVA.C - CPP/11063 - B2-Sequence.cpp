#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

#define MAX 105

using namespace std;
int num[MAX];
bool flage;
void B2_Sequence(int n);


int main()
{
	int t,cc = 0;
	while (scanf("%d", &t) != EOF)
	{
		for (int i = 0; i < t; i++) scanf("%d", &num[i]);
		flage = true;
		B2_Sequence(t);
		if (flage) printf("Case #%d: It is a B2-Sequence.\n",++cc);
		else printf("Case #%d: It is not a B2-Sequence.\n",++cc);
		printf("\n");
	}
	return 0;
}


void B2_Sequence(int n)
{
	if (num[0] < 1)
	{
		flage = false;
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (num[i] > num[i + 1])
		{
			flage = false;
			return;
		}
	}
	set < int > myset;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (myset.count(num[i] + num[j]))
			{
				flage = false;
				return;
			}
			else myset.insert(num[i] + num[j]);
		}
	}

}
