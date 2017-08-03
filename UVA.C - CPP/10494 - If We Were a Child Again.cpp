#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char ar[100000];
	int ans[10000];
	long long num,p,sum,k;
	char ch;
	while(scanf("%s %c %lld",ar,&ch,&num)==3)
	{
		if(ch == '%')
		{
			sum = 0;
			for(int i=0;i<strlen(ar);i++)
			{
				sum = sum + (ar[i] - 48);
				p = sum % num;
				p = p * 10;
				sum = p;
			}
			sum = sum / 10;
			printf("%lld\n",sum);
		}
		else if(ch == '/')
		{
			sum = 0;
			k = 0;
			for (int i=0;i<strlen(ar);i++)
			{
				sum = sum + (ar[i] - 48);
				ans[k++] = (sum / num);
				p = sum % num;
				p = p * 10;
				sum = p;
			}
			for(int i=0;i<k;i++)
			{
				if(ans[i] > 0)
				{
					p = i;
					break;
				}
			}
			for(int i=p;i<k;i++)
			{
				printf("%d",ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
