#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 1010
#define MAXP 124
char frist[MAX];
char second[MAX];
int num[MAXP];
int main()
{
	int found1, found2;
	while(gets(frist))
	{
		gets(second);
		for(int i = 97 ;i < MAXP ; i++)
		{
			found1 = found2 = 0;
			for(int j = 0 ;j < strlen(frist) ; j++)
			{
				if(frist[j] == i) found1++; 
			}
			for(int j = 0 ;j < strlen(second) ; j++)
			{
				if(second[j] == i) found2++;
			}
			num[i] = found1 < found2 ? found1 : found2;
		}
		for(int i = 97 ;i < MAXP ; i++)
		{
			if(num[i]!= 0) 
			{
				while(num[i]--) printf("%c",i);
			}
		}
		printf("\n");
	}
	return 0;
}

