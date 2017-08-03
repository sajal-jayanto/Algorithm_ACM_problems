#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char made(int);
char ar[30];
char ans[30];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long have_num,do_num,num;
	long long sum;
	char *stop;
	while(scanf("%s %lld %lld",ar,&have_num,&do_num)!=EOF)
	{	
		sum = strtol(ar,&stop,have_num);
		if( sum == 0) printf("%7d",0);
		else
		{
			for(int i = 0; i <10 ; i++) ans[i] = 32;
			int k = 0;
			while(sum)
			{
				num = sum % do_num;
				sum = sum / do_num;
				ans[k++] = made(num);
			}
			k = k - 1;
			if(k <= 6)
			{
				for(int i = 6 ;i >= 0; i--)
				{
					printf("%c",ans[i]);	
				}	
			}
			else printf("  ERROR");
		}
		printf("\n");
	}
	return 0;
}
char made(int num)
{
	if(num == 0) return '0';
	else if(num == 1) return '1';
	else if(num == 2) return '2';
	else if(num == 3) return '3';
	else if(num == 4) return '4';
	else if(num == 5) return '5';
	else if(num == 6) return '6';
	else if(num == 7) return '7';
	else if(num == 8) return '8';
	else if(num == 9) return '9';
	else if(num == 10) return 'A';
	else if(num == 11) return 'B';
	else if(num == 12) return 'C';
	else if(num == 13) return 'D';
	else if(num == 14) return 'E';
	else if(num == 15) return 'F';
}

