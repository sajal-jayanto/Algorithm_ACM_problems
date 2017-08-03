#include<stdio.h>
#include<string.h>
int main()
{
	int t,len,i,j,press;
	char ar[100];
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++){
		gets(ar);
		len=strlen(ar);
		press=0;
		for(j=0;j<len;j++){
			if(ar[j]=='a'||ar[j]=='d'||ar[j]=='g'||ar[j]=='j'||ar[j]=='m'||ar[j]=='p'||ar[j]=='t'||ar[j]=='w'||ar[j]==' ')press+=1;
			else if(ar[j]=='b'||ar[j]=='e'||ar[j]=='h'||ar[j]=='k'||ar[j]=='n'||ar[j]=='q'||ar[j]=='u'||ar[j]=='x')press+=2;
			else if(ar[j]=='c'||ar[j]=='f'||ar[j]=='i'||ar[j]=='l'||ar[j]=='o'||ar[j]=='r'||ar[j]=='v'||ar[j]=='y')press+=3;
			else if(ar[j]=='s'||ar[j]=='z')press+=4;
		}
		printf("Case #%d: %d\n",i,press);
	}
	return 0;
}
