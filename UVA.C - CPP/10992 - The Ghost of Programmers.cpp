#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
char ar[60];
int main()
{
	//freopen("output.txt","w",stdout);
	int ans,k,D2,D4,D5,D7,D11,D15,D20,D28,D36,D100,D400,count = 0;
	while(scanf("%s",ar)!=EOF)
	{
		if(strlen(ar) == 1 && ar[0] == '0') break;
		int len = strlen(ar);
		int str[len];
		int frist[len];
		ans = 0;
		if(count!=0) printf("\n");
		if(len <= 4) 
		{
			for(int i=0;i<len;i++) ans = (ans * 10) + (ar[i] - 48);
			if(ans < 2148) printf("%d\nNo ghost will come in this year\n",ans);
			else if(ans == 2148)
			{
				printf("2148\n");
				printf("Ghost of Tanveer Ahsan!!!\n");
				printf("Ghost of Shahriar Manzoor!!!\n");
				printf("Ghost of Adrian Kugel!!!\n");
				printf("Ghost of Anton Maydell!!!\n");
				printf("Ghost of Derek Kisman!!!\n");
				printf("Ghost of Rezaul Alam Chowdhury!!!\n");
				printf("Ghost of Jimmy Mardell!!!\n");
				printf("Ghost of Monirul Hasan!!!\n");
				printf("Ghost of K. M. Iftekhar!!!\n");
			}
			else 
			{
				k = ans - 2148;
				printf("%d\n",ans);
				if(k%2 == 0) printf("Ghost of Tanveer Ahsan!!!\n");
				if(k%5 == 0) printf("Ghost of Shahriar Manzoor!!!\n");
				if(k%7 == 0) printf("Ghost of Adrian Kugel!!!\n");
				if(k%11 == 0) printf("Ghost of Anton Maydell!!!\n");
				if(k%15 == 0) printf("Ghost of Derek Kisman!!!\n");
				if(k%20 == 0) printf("Ghost of Rezaul Alam Chowdhury!!!\n");
				if(k%28 == 0) printf("Ghost of Jimmy Mardell!!!\n");
				if(k%36 == 0) printf("Ghost of Monirul Hasan!!!\n");
				if((ans%4 == 0 && ans%100!=0) || ans%400 == 0) printf("Ghost of K. M. Iftekhar!!!\n");
				else if(k%2!=0 && k%5!=0 && k%7!=0 && k%11!=0 && k%15!=0 && k%20!=0 && k%28!=0 && k%36!=0)
				printf("No ghost will come in this year\n");
				
			}
		}
		else 
		{
			D2 = D4 = D5 = D7 = D11 = D15 = D20 = D28 = D36 = D100 = D400 = 0;
			for(int i=0;i<len;i++) str[i] = frist[i] = 0;
			for(int i=len-1;i>=0;i--) str[i] = ar[i] - 48;
			frist[len-1] = 8;frist[len-2] = 4;frist[len-3] = 1;frist[len-4] = 2;
			for(int i=0;i<len;i++)
			{
				D4 = D4 + str[i];
				D100 = D100 + str[i];
				D400 = D400 + str[i];
				D4 = D4%4;
				D100 = D100%100;
				D400 = D400%400;
				D4 = D4 * 10;
				D100 = D100  * 10;
				D400 = D400 * 10;
			}
			if((D4 == 0 && D100!=0) || D400 == 0) D4 = 0;
			else D4 = 1;
			for(int i=len-1;i>=0;i--)
			{
				if(str[i] >= frist[i]) str[i] = str[i] - frist[i];
				else str[i] = (str[i] + 10) - frist[i],frist[i-1] = frist[i-1] + 1;
			}
			for(int i=0;i<len;i++)
			{
				D2 = D2  + str[i];
				D5 = D5 + str[i];
				D7 = D7 + str[i];
				D11 = D11 + str[i];
				D15 = D15 + str[i];
				D20 = D20 + str[i];
				D28 = D28 + str[i];
				D36 = D36 + str[i];
				D2 = D2%2;
				D5 = D5%5;
				D7 = D7%7;
				D11 = D11%11;
				D15 = D15%15;
				D20 = D20%20;
				D28 = D28%28;
				D36 = D36%36;
				D2 = D2 * 10;
				D5 = D5 * 10;
				D7 = D7 * 10;
				D11 = D11 * 10;
				D15 = D15 * 10;
				D20 = D20 * 10;
				D28 = D28 * 10;
				D36 = D36 * 10;
			}
			printf("%s\n",ar);
			if(D2 == 0) printf("Ghost of Tanveer Ahsan!!!\n");
			if(D5 == 0) printf("Ghost of Shahriar Manzoor!!!\n");
			if(D7 == 0) printf("Ghost of Adrian Kugel!!!\n");
			if(D11 == 0) printf("Ghost of Anton Maydell!!!\n");
			if(D15 == 0) printf("Ghost of Derek Kisman!!!\n");
			if(D20 == 0) printf("Ghost of Rezaul Alam Chowdhury!!!\n");
			if(D28 == 0) printf("Ghost of Jimmy Mardell!!!\n");
			if(D36 == 0) printf("Ghost of Monirul Hasan!!!\n");
			if(D4 == 0) printf("Ghost of K. M. Iftekhar!!!\n");
			if(D2!=0 && D5!=0 && D7!=0 && D11!=0 && D15!=0 && D20!=0 && D28!=0 && D36!=0 && D4!=0)
			printf("No ghost will come in this year\n");
			//printf("%d %d %d %d %d %d %d %d %d %d %d\n",D2,D4,D5,D7,D11,D15,D20,D28,D36,D100,D400);
		}
		count++;
	}
	return 0;	
}
