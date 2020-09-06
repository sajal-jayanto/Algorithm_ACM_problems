#include<bits/stdc++.h>

using namespace std;

int main(){

	int t ;
	long long number , ans , cnt ;
	scanf("%d" , &t);
	while(t--){
		
		scanf("%lld" , &number);
		cnt = (number / 2) + 1;
		ans = ( cnt * cnt ) + ( (cnt - 1) * (cnt - 1));
		
		printf("%lld\n" , ans);	
	}
	return 0;
}
