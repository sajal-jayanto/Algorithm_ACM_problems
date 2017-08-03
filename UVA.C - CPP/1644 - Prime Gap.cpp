#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define  MAX  1299719
bool ar[MAX];
void is_prime();
int main()
{
	//freopen("output.txt","w",stdout);
	is_prime();
	int num,a,b;
	while(scanf("%d",&num) && num)
	{
		a = b = num;
		while(ar[a] != false) a++;
		while(ar[b] != false) b--;
		num = a - b;
		printf("%d\n",num);	
	}
	return 0;
}
void is_prime()
{
	for(int i = 2 ;i < sqrt(MAX) ; i++)
	{
		if(i == 2 || ar[i] == false)
		{
			for(int j = i + i ; j< MAX ; j = j + i)
			{
				ar[j] = true;	
			} 
		}
	}
}
