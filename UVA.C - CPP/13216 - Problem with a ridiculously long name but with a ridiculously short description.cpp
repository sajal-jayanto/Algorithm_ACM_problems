#include<bits/stdc++.h>

using namespace std;

int main(){
	
	//freopen("input.txt" , "r" , stdin);
	int t , len ;
	char str[100000];
	scanf("%d" , &t);
	getchar();
	while(t--){
		
		scanf("%s" , str);
		
		len = strlen(str);
		
		if( (str[0] == '0' || str[0] == '1') && len == 1) {	
			if(str[0] == '0') printf("1");
			else printf("66");
		}
		else {
			
			int mod = 0;
			
			for(int i = 0 ; i < len ; ++i){
				
				mod = ( (mod * 10) + (str[i] - '0') );
				mod = mod % 5;
			}
			
			mod = mod - 2;
			
			if(mod < 0) mod = mod + 5;
			
			if(mod == 0) printf("56");
			else if(mod == 1) printf("96");
			else if(mod == 2) printf("36");
			else if(mod == 3) printf("76");
			else if(mod == 4) printf("16");
		}
		
		printf("\n");
	}
	
	
	return 0;
}



