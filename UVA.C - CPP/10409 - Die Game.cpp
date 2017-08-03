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
void make_north();
void make_south();
void make_east();
void make_west();
int num[10];
char kye[10];

int main()
{
	int t;
	while (scanf("%d", &t) && t)
	{
		for (int i = 0; i < 6; i++) num[i] = i + 1;
		gets(kye);
		while (t--)
		{
			gets(kye);
			if (strcmp(kye, "north") == 0) make_north();
			else if (strcmp(kye, "south") == 0) make_south(); 
			else if (strcmp(kye, "east") == 0) make_east();
			else make_west();
		}
		printf("%d\n", num[0]);
	}
	return 0;
}

void make_north()
{
	swap(num[0], num[1]);
	swap(num[4], num[5]);
	swap(num[0], num[5]);
}

void make_south()
{
	swap(num[0], num[1]);
	swap(num[4], num[5]);
	swap(num[1], num[4]);
}

void make_east()
{
	swap(num[0], num[2]);
	swap(num[2], num[3]);
	swap(num[2], num[5]);
}

void make_west()
{
	swap(num[2], num[3]);
	swap(num[0], num[3]);
	swap(num[3], num[5]);
}