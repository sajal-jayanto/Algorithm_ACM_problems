#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int valu(char);
int data(int);
char ar[1000];
char ans[100];
int main()
{
	//freopen("output.txt","w",stdout);
	int sum;
	while(scanf("%s",ar) == 1)
	{
		sum = 0;
		if(isdigit(ar[0]) == 0)
		{
			for(int i=0;i<strlen(ar);)
			{
				if(valu(ar[i]) < valu(ar[i+1]))
				{
					sum = sum + (valu(ar[i+1]) - valu(ar[i]));
					i = i + 2;
				}	
				else 
				{
					sum = sum + valu(ar[i]);
					i = i + 1;
				}
			}
			data(sum);
			if(strcmp(ar,ans) == 0)
			{
				printf("%d",sum);
			}
		}
		else 
		{
			sum = atoi(ar); 
			data(sum);
			for(int i=0;i<strlen(ans);i++)
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
int valu(char ch)
{
	if(ch =='I') return 1;
	if(ch =='V') return 5;
	if(ch =='X') return 10;
	if(ch =='L') return 50;
	if(ch =='C') return 100;
	if(ch =='D') return 500;
	if(ch =='M') return 1000;
}
int data(int sum)
{
	int n,k = 0;
	if(sum >= 1000)
	{
		n = sum / 1000;
		sum = sum % 1000;
		n = n * 1000;
		if(n == 1000)
		{
			ans[k++] = 'M';
		}else if(n == 2000)
		{
			ans[k++] = 'M';
			ans[k++] = 'M';	
		}else if(n == 3000)
		{
			ans[k++] = 'M';
			ans[k++] = 'M';
			ans[k++] = 'M';
					
		}else if(n == 4000)
		{
			ans[k++] = 'M';
			ans[k++] = 'M';
			ans[k++] = 'M';
			ans[k++] = 'M';
		}else if(n == 5000)
		{
			ans[k++] = 'M';
			ans[k++] = 'M';
			ans[k++] = 'M';
			ans[k++] = 'M';
			ans[k++] = 'M';
		}
	}
	if(sum >= 100)
	{
		n = sum / 100;
		sum = sum % 100;
		n = n * 100;
		if(n == 100)
		{
			ans[k++] = 'C';
		}else if(n == 200)
		{
			ans[k++] = 'C';
			ans[k++] = 'C';
		}else if(n == 300)
		{
			ans[k++] = 'C';
			ans[k++] = 'C';
			ans[k++] = 'C';
		}else if(n == 400)
		{
			ans[k++] = 'C';
			ans[k++] = 'D';
		}else if(n == 500)
		{
			ans[k++] = 'D';
		}else if(n == 600)
		{
			ans[k++] = 'D';
			ans[k++] = 'C';
		}else if(n == 700)
		{
			ans[k++] = 'D';
			ans[k++] = 'C';
			ans[k++] = 'C';
		}else if(n == 800)
		{
			ans[k++] = 'D';
			ans[k++] = 'C';
			ans[k++] = 'C';
			ans[k++] = 'C';
		}else if(n == 900) 
		{
			ans[k++] = 'C';
			ans[k++] = 'M';
		}
	}
	if(sum >=10)
	{
		n = sum / 10;
		sum = sum % 10;
		n = n * 10;
		if(n == 10) 
		{
			ans[k++] = 'X';
		}else if(n == 20)
		{
			ans[k++] = 'X';
			ans[k++] = 'X';	
		}else if(n == 30)
		{
			ans[k++] = 'X';
			ans[k++] = 'X';
			ans[k++] = 'X';
		}else if(n == 40)
		{
			ans[k++] = 'X';
			ans[k++] = 'L';
		}else if(n == 50)
		{
			ans[k++] = 'L';
		}else if(n == 60)
		{
			ans[k++] = 'L';
			ans[k++] = 'X';
		}else if(n == 70)
		{
			ans[k++] = 'L';
			ans[k++] = 'X';
			ans[k++] = 'X';
		}else if(n == 80)
		{
			ans[k++] = 'L';
			ans[k++] = 'X';
			ans[k++] = 'X';
			ans[k++] = 'X';
		}else if(n == 90)
		{
			ans[k++] = 'X';
			ans[k++] = 'C';
		}
	}
	if(sum >= 1)
	{
		if(sum == 1) 
		{
			ans[k++] = 'I';
		}else if(sum == 2)
		{
			ans[k++] = 'I';
			ans[k++] = 'I';	
		}else if(sum == 3)
		{
			ans[k++] = 'I';
			ans[k++] = 'I';
			ans[k++] = 'I';
		}else if(sum == 4)
		{
			ans[k++] = 'I';
			ans[k++] = 'V';
		}else if(sum == 5)
		{
			ans[k++] = 'V';
		}else if(sum == 6)
		{
			ans[k++] = 'V';
			ans[k++] = 'I';
		}else if(sum == 7)
		{
			ans[k++] = 'V';
			ans[k++] = 'I';
			ans[k++] = 'I';
		}else if(sum == 8)
		{
			ans[k++] = 'V';
			ans[k++] = 'I';
			ans[k++] = 'I';
			ans[k++] = 'I';
		}else if(sum == 9)
		{
			ans[k++] = 'I';
			ans[k++] = 'X';
		}
	}
	ans[k] = '\0';
}

