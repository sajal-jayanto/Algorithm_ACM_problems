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

using namespace std;

int main()
{
	int t;
	char str[12];
	scanf("%d", &t);
	gets(str);
	while (t--)
	{
		gets(str);
		int len = strlen(str);
		sort(str, str + len);
		printf("%s\n", str);
		while (next_permutation(str, str + len)) printf("%s\n", str);
		printf("\n");
	}
	return 0;

}