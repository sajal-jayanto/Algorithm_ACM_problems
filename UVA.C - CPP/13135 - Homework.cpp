#include<bits/stdc++.h>

using namespace std;

int main(){

	//freopen("input.txt" , "r" , stdin);

	vector < long long > ve;
	vector < int > ve_ans;
	
	long long ans = 1 , num;
	
	for(long long i = 3 ;  ; ++i){
		
		ans = (i * (i - 1)) / 2;
		ve.push_back(i - 1);
		ve_ans.push_back(ans);
		if(ans > 50000000) break;
	}
	
	int t;
	scanf("%d" , &t);
	while(t--){
		
		scanf("%lld" , &num);
		
		if(num == 3){
			printf("1\n");
		}
		else if( binary_search(ve_ans.begin(), ve_ans.end(), num) ){
			printf("%lld\n" , ve[lower_bound(ve_ans.begin(), ve_ans.end(), num)  - ve_ans.begin() - 1]);
		}
		else printf("No solution\n");
		
	}
	
	return 0;
}
