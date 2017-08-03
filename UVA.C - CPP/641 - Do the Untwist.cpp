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
int find(char);

char bord[30] = "_abcdefghijklmnopqrstuvwxyz.";

int main()
{
	//freopen("output.txt","w",stdout);
	//freopen("input.txt","r",stdin);
	
	int t,n,index,len;
	char name[1000];
	int p[1000];
	while(scanf("%d",&t) && t)
	{
		scanf("%s",name);
		len = strlen(name) ;
		for(int i = 0 ; i < len ; i++)
		{
			n = find(name[i]);
			index = (t * i) % len;
			p[index] = (n + i) % 28;
		}
		for(int i = 0 ; i < len ; i++)
		{
			printf("%c",bord[p[i]]);
		}
		printf("\n");	
	}
	return 0;
}
int find(char ch)
{

	for(int i = 0 ; i < 28 ; i++) if(bord[i] == ch) return i;
	
}
