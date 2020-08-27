#include<bits/stdc++.h>

using namespace std;

bool is_it_runaround(int number){
	
	int len = floor(log10(number) + 1);
	int lim = (1 << len) - 1;
	string str = to_string(number);
	int pos = 0 , jump ;
	lim = lim | (1 << pos);
	
	while(lim > 0){
		
		jump = (str[pos] - '0') + pos + 1;
		pos = (jump % len) ? (jump % len) - 1 :  len - 1;
		if( (lim & (1 << pos) ) == 0) return false;
		lim = lim & ~(1 << pos);
	}
	
	return true;
	
}

bool is_it_valid(int number) {
	
	int digit = 0 , n ;
	
	while(number > 0) {
		
		n = number % 10;
		if(n == 0) return false;
		if((digit & (1 << n)) != 0) return false;
		digit = digit | (1 << n);
		number = number / 10;
	}
	
	return true;
}

int main(){

	freopen("input.txt", "r" , stdin);
	
	int number , lim = 10000000 , cc = 0; //9999999
	vector < int > ve ;
	
	for(int i = 10 ; i < lim ; ++i){
		if( is_it_valid(i) && is_it_runaround(i) ) ve.push_back(i);	
	}
	
	while(scanf("%d" , &number) && number){
		
		
		int index = lower_bound(ve.begin() , ve. end() , number - 1) - ve.begin();
		
		printf("Case %d: %d\n" , ++cc , ve[index]);
			
	}
	return 0;
}
