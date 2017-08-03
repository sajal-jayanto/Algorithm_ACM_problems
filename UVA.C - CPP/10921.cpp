#include<stdio.h>
#include<string.h>
int main()
{
	char ar[31],ar2[31];
	int i,len;
	while(scanf("%s",ar)!=EOF){
		len=strlen(ar);
		for(i=0;i<len;i++){
			if(ar[i]=='A' || ar[i]=='B'|| ar[i]=='C')ar2[i]=50;
			else if(ar[i]=='D' || ar[i]=='E'|| ar[i]=='F')ar2[i]=51;
			else if(ar[i]=='G' || ar[i]=='H'|| ar[i]=='I')ar2[i]=52;
			else if(ar[i]=='J' || ar[i]=='K'|| ar[i]=='L')ar2[i]=53;
			else if(ar[i]=='M' || ar[i]=='N'|| ar[i]=='O')ar2[i]=54;
			else if(ar[i]=='P' || ar[i]=='Q'|| ar[i]=='R'||ar[i]=='S')ar2[i]=55;
			else if(ar[i]=='T' || ar[i]=='U'|| ar[i]=='V')ar2[i]=56;
			else if(ar[i]=='W' || ar[i]=='X'|| ar[i]=='Y'||ar[i]=='Z')ar2[i]=57;
			else ar2[i]=ar[i];
		}
		for(i=0;i<len;i++)printf("%c",ar2[i]);
		printf("\n");
	}
}

