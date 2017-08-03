#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void take(int);
int ar[1000000][2] = {0};
int count = 0;
int main()
{
	int num;
	while(scanf("%d",&num) == 1)
	{
		take(num);
	}
	for(int i=0;i<count;i++)
	{
		printf("%d %d\n",ar[i][0],ar[i][1]);
	}
	return 0;
}
void take(int num)
{
	int found = 0;
	if(count == 0)
	{
		ar[count][0] = num;
		ar[count][1]++;
		count++;	
	} 
	else
	{
		for(int i=0;i<count;i++)
		{
			if(ar[i][0] == num)
			{
				ar[i][1]++;
				found = 1;	
			} 
		}
		if(found == 0)
		{
			ar[count][0] = num;
			ar[count][1]++;
			count++;
		}
	}
}
