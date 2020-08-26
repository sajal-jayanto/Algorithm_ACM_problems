#include<bits/stdc++.h>

using namespace std;

struct triples {
	int start ;
	int end ;
	int hight ;
	
	triples(){		
		start = 0;
		end = 0;
		hight = 0;
	}
	
	triples(int a , int b , int c){
		start = a;
		end = b;
		hight = c;
	}
	
};

triples ve[5010];
int save[10010] , lim = 0;


int find_max_hight(int index){
	
	int hight = 0;
	
	for(int i = 0 ; i < lim ; ++i){
		if(ve[i].start <= index && ve[i].end > index) hight = max(hight , ve[i].hight);
	}
	
	return hight;
}

int main(){
	
	//freopen("input.txt" , "r" , stdin);
	int a , b , c , min_start = (1 << 30) , max_end = -1 , last_print;
	
	while(scanf("%d %d %d", &a , &b , &c) == 3){
		
		ve[lim++] = triples(a , c , b);
		min_start = min(min_start , a);
		max_end = max(max_end , c);
	}
	
	for(int i = min_start ; i <= max_end ; ++i){
		save[i] = find_max_hight(i);
	}
	 
	for(int i = min_start  ; i <= max_end ; ++i) {
		
		if(save[i] != save[i - 1]){
			if(i == min_start) printf("%d %d" , i , save[i]);
			else printf(" %d %d" , i , save[i]); 	
		}
	}
	printf("\n");
	
	return 0;
}


