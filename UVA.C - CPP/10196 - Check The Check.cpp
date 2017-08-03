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
bool chak_k(int a, int b);
bool chak_K(int a, int b);
char bord[8][8];

int main()
{
	//freopen("input.txt", "r", stdin);
	bool flage, k, K;
	int ki, kj, Ki, Kj, cc = 0;
	while (true)
	{
		flage = true;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf(" %c", &bord[i][j]);
				if (isalpha(bord[i][j]) != 0 && flage) flage = false;
				if (bord[i][j] == 'k') ki = i, kj = j;
				if (bord[i][j] == 'K') Ki = i, Kj = j;
			}
		}
		if (flage) break;
		k = chak_k(ki, kj);
		K = chak_K(Ki, Kj);
		if (k && K) printf("Game #%d: white king is in check.\n", ++cc);
		else if (k) printf("Game #%d: black king is in check.\n", ++cc);
		else if (K)  printf("Game #%d: white king is in check.\n", ++cc);
		else printf("Game #%d: no king is in check.\n", ++cc);
	}
	return 0;
}

bool chak_k(int a, int b)
{
	if (a - 1 >= 0 && b + 1 < 8 && bord[a - 1][b + 1] == 'P') return true;
	if (a - 1 >= 0 && b - 1 >= 0 && bord[a - 1][b - 1] == 'P') return true;
	if (a - 1 >= 0 && bord[a - 1][b] == 'K' || a + 1 < 8 && bord[a + 1][b] == 'K') return true;
	if (b - 1 >= 0 && bord[a][b - 1] == 'K' || b + 1 < 8 && bord[a][b + 1] == 'K') return true;
	if (a + 1 < 8 && b + 1 < 8 && bord[a + 1][b + 1] == 'K') return true;
	if (a - 1 >= 0 && b - 1 >= 0 && bord[a - 1][b - 1] == 'K') return true;
	if (a + 1 < 8 && b - 1 >= 0 && bord[a + 1][b - 1] == 'K') return true;
	if (a - 1 >= 0 && b + 1 < 8 && bord[a - 1][b + 1] == 'K') return true;
	if (a - 2 >= 0 && b - 1 >= 0 && bord[a - 2][b - 1] == 'N') return true;
	if (a - 1 >= 0 && b - 2 >= 0 && bord[a - 1][b - 2] == 'N') return true;
	if (a + 1 < 8 && b - 2 >= 0 && bord[a + 1][b - 2] == 'N') return true;
	if (a + 2 < 8 && b - 1 >= 0 && bord[a + 2][b - 1] == 'N') return true;
	if (a + 2 < 8 && b + 1 < 8 && bord[a + 2][b + 1] == 'N') return true;
	if (a + 1 < 8 && b + 2 < 8 && bord[a + 1][b + 2] == 'N') return true;
	if (a - 1 >= 0 && b + 2 < 8 && bord[a - 1][b + 2] == 'N') return true;
	if (a - 2 >= 0 && b + 1 < 8 && bord[a - 2][b + 1] == 'N') return true;
	for (int i = a + 1; i < 8; i++)
	{
		if (bord[i][b] != '.')
		{
			if (bord[i][b] == 'R' || bord[i][b] == 'Q') return true;
			else break;
		}
	}
	for (int i = a - 1; i >= 0; i--)
	{
		if (bord[i][b] != '.')
		{
			if (bord[i][b] == 'R' || bord[i][b] == 'Q') return true;
		}
	}
	for (int i = b + 1; i < 8; i++)
	{
		if (bord[a][i] != '.')
		{
			if (bord[a][i] == 'R' || bord[a][i] == 'Q') return true;
		}
	}
	for (int i = b - 1; i >= 0; i--)
	{
		if (bord[a][i] != '.')
		{
			if (bord[a][i] == 'R' || bord[a][i] == 'Q') return true;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a + i < 8 && b + i < 8 && bord[a + i][b + i] != '.')
		{
			if (bord[a + i][b + i] == 'B' || bord[a + i][b + i] == 'Q') return true;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a - i >= 0 && b - i >= 0 && bord[a - i][b - i] != '.')
		{
			if (bord[a - i][b - i] == 'B' || bord[a - i][b - i] == 'Q') return true;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a + i < 8 && b - i >= 0 && bord[a + i][b - i] != '.')
		{
			if (bord[a + i][b - i] == 'B' || bord[a + i][b - i] == 'Q') return true;
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a - i >= 0 && b + i < 8 && bord[a - i][b + i] != '.')
		{
			if (bord[a - i][b + i] == 'B' || bord[a - i][b + i] == 'Q') return true;
			else break;
		}
	}
	return false;

}

bool chak_K(int a, int b)
{
	if (a - 1 >= 0 && b + 1 < 8 && bord[a - 1][b + 1] == 'p') return true;
	if (a - 1 >= 0 && b - 1 >= 0 && bord[a - 1][b - 1] == 'p') return true;
	if (a - 1 >= 0 && bord[a - 1][b] == 'k' || a + 1 < 8 && bord[a + 1][b] == 'k') return true;
	if (b - 1 >= 0 && bord[a][b - 1] == 'k' || b + 1 < 8 && bord[a][b + 1] == 'k') return true;
	if (a + 1 < 8 && b + 1 < 8 && bord[a + 1][b + 1] == 'k') return true;
	if (a - 1 >= 0 && b - 1 >= 0 && bord[a - 1][b - 1] == 'k') return true;
	if (a + 1 < 8 && b - 1 >= 0 && bord[a + 1][b - 1] == 'k') return true;
	if (a - 1 >= 0 && b + 1 < 8 && bord[a - 1][b + 1] == 'k') return true;
	if (a - 2 >= 0 && b - 1 >= 0 && bord[a - 2][b - 1] == 'n') return true;
	if (a - 1 >= 0 && b - 2 >= 0 && bord[a - 1][b - 2] == 'n') return true;
	if (a + 1 < 8 && b - 2 >= 0 && bord[a + 1][b - 2] == 'n') return true;
	if (a + 2 < 8 && b - 1 >= 0 && bord[a + 2][b - 1] == 'n') return true;
	if (a + 2 < 8 && b + 1 < 8 && bord[a + 2][b + 1] == 'n') return true;
	if (a + 1 < 8 && b + 2 < 8 && bord[a + 1][b + 2] == 'n') return true;
	if (a - 1 >= 0 && b + 2 < 8 && bord[a - 1][b + 2] == 'n') return true;
	if (a - 2 >= 0 && b + 1 < 8 && bord[a - 2][b + 1] == 'n') return true;
	for (int i = a + 1; i < 8; i++)
	{
		if (bord[i][b] != '.')
		{
			if (bord[i][b] == 'r' || bord[i][b] == 'q') return true;
			else break;
		}
	}
	for (int i = a - 1; i >= 0; i--)
	{
		if (bord[i][b] != '.')
		{
			if (bord[i][b] == 'r' || bord[i][b] == 'q') return true;
			else break;
		}
	}
	for (int i = b + 1; i < 8; i++)
	{
		if (bord[a][i] != '.')
		{
			if (bord[a][i] == 'r' || bord[a][i] == 'q') return true;
			else break;
		}
	}
	for (int i = b - 1; i >= 0; i--)
	{
		if (bord[a][i] != '.')
		{
			if (bord[a][i] == 'r' || bord[a][i] == 'q') return true;
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a + i < 8 && b + i < 8 && bord[a + i][b + i] != '.')
		{
			if (bord[a + i][b + i] == 'b' || bord[a + i][b + i] == 'q') return true;
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a - i >= 0 && b - i >= 0 && bord[a - i][b - i] != '.')
		{
			if (bord[a - i][b - i] == 'b' || bord[a - i][b - i] == 'q') return true;
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a + i < 8 && b - i >= 0 && bord[a + i][b - i] != '.')
		{
			if (bord[a + i][b - i] == 'b' || bord[a + i][b - i] == 'q') return true;
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (a - i >= 0 && b + i < 8 && bord[a - i][b + i] != '.')
		{
			if (bord[a - i][b + i] == 'b' || bord[a - i][b + i] == 'q') return true;
			else break;
		}
	}
	return false;
}
