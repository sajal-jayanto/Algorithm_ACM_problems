#include<stdio.h>
#include<stdio.h>
int main()
{
	char ar[100][100];
	int t,i,j=0,n,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)scanf("%s",ar[i]);
	i=0;
	k=t;
	if(t<=16){
		while(j!=4){
			printf("%s: Happy\n",ar[i]);
			if(i==t-1)i=0;
			else i++;
			printf("%s: birthday\n",ar[i]);
			if(i==t-1)i=0;
			else i++;
			printf("%s: to\n",ar[i]);
			if(i==t-1)i=0;
			else i++;
			if(j!=2)printf("%s: you\n",ar[i]);
			else printf("%s: Rujia\n",ar[i]);
			if(i==t-1)i=0;
			else i++;
			j++;	
		}
	}
	else {
		if(t>16)
		while(1){
			if(t==32||t==48||t==64||t==80||t==96||t==112)break;
			t++;
		}
		n=t/4;
		while(n--){
			printf("%s: Happy\n",ar[i]);
			if(i==k-1)i=0;
			else i++;
			printf("%s: birthday\n",ar[i]);
			if(i==k-1)i=0;
			else i++;
			printf("%s: to\n",ar[i]);
			if(i==k-1)i=0;
			else i++;
			if(j%2==0&&j!=0){
				printf("%s: Rujia\n",ar[i]);
				j=-2;
			}
			else printf("%s: you\n",ar[i]);
			if(i==k-1)i=0;
			else i++;
			j++;
		}	
	}
	return 0;
}

