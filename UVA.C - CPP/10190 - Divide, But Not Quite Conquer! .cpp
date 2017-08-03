#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>



using namespace std;

int main()
{
	//freopen("output.txt","w",stdout);
	int count[10000];
	int num,mod,k;
	bool flage;
	while(scanf("%d %d",&num,&mod) != EOF)
	{
		k = 0;
		flage = true;
		if(num < mod || num < 2 || mod < 2)
		{
			printf("Boring!\n");
			continue;	
		} 
		if(num / mod == 0)
		{
			printf("%d 1\n",num);
			continue;
		}
		while(true)
		{
			if(num % mod == 0)
			{
				count[k++] = num;
				num = num / mod;
				if(num == 1) 
				{
					count[k++] = num;
					break;
				}
			}
			else 
			{
				flage = false;
				break;
			}
		}
		if( flage == false) printf("Boring!\n");
		else if(k != 0)
		{
			printf("%d",count[0]);
			for(int i = 1 ; i < k ; i++) printf(" %d",count[i]);
			printf("\n");
		}	
	}
 	return 0;
}

