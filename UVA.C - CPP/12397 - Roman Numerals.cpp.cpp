#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int data(int);
char ans[100];
int main()
{
	//freopen("output.txt","w",stdout);
	int num,sum;
	while(scanf("%d",&num) == 1)
    {
        data(num);
        sum = 0;
        for(int i = 0 ; i < strlen(ans) ; i++)
        {
            if(ans[i] == 'I') sum = sum + 1;
            if(ans[i] == 'V') sum = sum + 2;
            if(ans[i] == 'X') sum = sum + 2;
            if(ans[i] == 'L') sum = sum + 2;
            if(ans[i] == 'C') sum = sum + 2;
            if(ans[i] == 'D') sum = sum + 3;
            if(ans[i] == 'M') sum = sum + 4;
        }
        printf("%d\n",sum);
    }
	return 0;
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

