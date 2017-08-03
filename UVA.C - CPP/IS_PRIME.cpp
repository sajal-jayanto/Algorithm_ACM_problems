#include<stdio.h>
#include<math.h>
#define MAX 1000
int ar[MAX];
int main()
{
	for(int i=2;i<sqrt(MAX);i++)
	{
		for(int j=i+i;j<=MAX;j=j+i)
		{
			ar[j-1] = 1;
		}
	}
	return 0;
}
