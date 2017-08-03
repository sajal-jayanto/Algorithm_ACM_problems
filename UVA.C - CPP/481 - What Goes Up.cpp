#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <list>
#define MAX 100000
#define MAX_INT 2000000000
using namespace std;

int binary_scearch(int low, int high, int kye);

long long have[MAX];
int DP[MAX];
int indx[MAX];


int main()
{
    freopen("input.txt", "r", stdin);
	long long num, *save;
	int k = 0;
	int cnt = -1;
	while (scanf("%lld", &num) == 1)
	{
		have[k] = num;
		DP[k++] = MAX_INT;
	}
	DP[0] = (int) have[0];

	for (int i = 1; i < k; i++)
	{
		indx[i] = binary_scearch( 0 , i , have[i] );
		if (cnt < indx[i]) cnt = indx[i];
	}
	printf("%d\n-\n", cnt + 1);
	save = (long long*)malloc( (cnt + 1) * sizeof(long long));
	int temp = cnt;
	for (int i = k - 1; i >= 0; i--)
	{
		if (indx[i] == temp)save[temp--] = have[i];
	}
	for (int i = 0; i < cnt + 1; i++) printf("%lld\n", save[i]);

}


int binary_scearch(int low, int high, int kye)
{
	int mid;

	while (low <= high)
	{
		mid = low + ((high - low) >> 1);

		if (DP[mid] > kye) high = mid - 1;
		else if (DP[mid] == kye) return mid;
		else if (mid + 1 < high && DP[mid + 1] >= kye) { DP[mid + 1] = kye; return  mid + 1; }
		else low = mid + 1;
	}
	if (mid == low) { DP[mid] = kye; return mid; }
	DP[mid + 1] = kye;
	return mid + 1;

}

