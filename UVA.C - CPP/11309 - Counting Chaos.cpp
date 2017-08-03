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

bool Palindrome(int a, int b);
void upgret(int *a, int *b);

/*int main()
{
	//freopen("input.txt", "r", stdin);
	int hour, mint;
	char ch;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%c%d", &hour, &ch, &mint);
		//printf("%02d:%02d -->", hour, mint);
		while (true)
		{
			upgret(&hour, &mint);
			if (Palindrome(hour, mint))
			{
				printf("%02d%c%02d\n", hour, ch, mint);
				break;
			}
		}
	}

	return 0;
}*/

void upgret(int *a, int *b)
{
	if ((*b) == 59)
	{
		(*b) = 0;
		if ((*a) == 23) (*a) = 0;
		else (*a)++;
	}
	else (*b)++;
}


bool Palindrome(int a, int b)
{
	int num = (a * 100) + b;
	int rev = 0;
	int temp = num;
	while (temp)
	{
		rev = (rev * 10) + temp % 10;
		temp = temp / 10;
	}
	if (rev == num) return true;
	return false;
}

