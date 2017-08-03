#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
long long big_num();
long long small_num();
char ar[100];
using namespace std;
int main()
{
	while(scanf("%s",ar) == 1)
	{
		long long a,b,c;
		a = big_num();
		b = small_num();
		c = big_num() - small_num();
		printf("%lld - %lld = %lld = 9 * %lld\n",a,b,c,c/9);
	}
	return 0;
}
long long big_num()
{
	long long big = 0;
	sort(ar,ar+strlen(ar));
	for(int i=strlen(ar)-1;i>=0;i--)
	{
		big = (big * 10) + (ar[i] - 48);
	}
	return big;
}
long long small_num()
{
	long long small = 0;
	int count = 0;
	if(ar[0] == '0')
	{
		for(int i=0;i<strlen(ar);i++)
		{
			if(ar[i] == '0') count++;
		}
		ar[0] = ar[count];
		ar[count] = '0'; 
	}
	for(int i=0;i<strlen(ar);i++)
	{
		small = (small * 10) + (ar[i] - 48);
	}
	return small;
}
