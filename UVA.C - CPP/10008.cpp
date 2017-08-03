#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,ab,len,j,coun=0,k=0,low,hig;
	char ar[20][100];
	int get[26];
	int get2[26];
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		gets(ar[i]);
	}
	for(ab=65;ab<91;ab++){
		for(i=0;i<=n;i++){
		 len=strlen(ar[i]);
			for(j=0;j<len;j++){
				if(ar[i][j]==ab||ar[i][j]==ab+32)
				coun++;
			}		
		}
		if(coun>=1){
		 get[k]=coun;
		 get2[k]=ab;
		 k++;
		}
		coun=0;	
    }
    hig=get[0];
    for(i=0;i<k;i++){
    	if(hig<get[i])
    	hig=get[i];
    }
    low=get[0];
    for(i=0;i<k;i++){
    	if(low>get[i])
    	low=get[i];
    }
    for(i=hig;i>=low;i--){
    	for(j=0;j<k;j++){
    		if(i==get[j])
    		printf("%c %d\n",get2[j],get[j]);
    	}
    	
    }
 return 0;   

}
