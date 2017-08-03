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
#define MAX 105

using namespace std;

struct bord
{
	char name[50];
	long long sum;
	
}formula[MAX];
bool cmp(const bord &a, const bord &b)
{
	if(a.sum < b.sum) return true;
	else return false;
}
bool cmp1(const bord &a, const bord &b)
{
	if(a.name > b.name) return true;
	else return false;
}
int main()
{
	//freopen("output.txt","w",stdout);
	int t,len,min,sec,msec,count,n = 0;
	char input[500];
	char *p;
	while(scanf("%d",&t) != EOF)
	{
		getchar();
		if(n != 0) printf("\n");
		for(int i = 0 ; i < t ; i++)
		{
			gets(input);
			len = 0;
			p = strtok(input," ");
			while(p != NULL)
			{
				if(len == 0) strcpy(formula[i].name,p);
				if(len == 2) min = atoi(p);
				if(len == 4) sec = atoi(p);
				if(len == 6) msec = atoi(p);
				p = strtok(NULL," ");
				len++;
			}
			formula[i].sum = (((min * 60) + sec) * 100) + msec;
		}		
		sort(formula, formula + t, cmp1);
		sort(formula, formula + t, cmp);
		count = 0;
		for(int i = 0 ; i < t ; i++)
		{
			if(i % 2 == 0) printf("Row %d\n",++count);
			printf("%s\n",formula[i].name);	
		}
		n++;
	}
	return 0;
}


