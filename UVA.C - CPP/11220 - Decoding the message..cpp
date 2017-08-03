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
	//freopen("input.txt","r",stdin);
	char mas[5000],*p;
	int t,n,count = 0;
	string a,b;
	scanf("%d",&t);
	gets(mas);
	gets(mas);
	while(t--)
	{
		printf("Case #%d:\n",++count);
		while(gets(mas) && strlen(mas) != 0)
		{
			n = 0;
			b = "";
			a = "";
			p = strtok(mas," ");
			n++;
			while(p !=  NULL)
			{
				a = p;
				if(a.length() >= n) 
				{
					b = b + a.at(n - 1);
					n++;
				}
				p = strtok(NULL ," ");
			}
			printf("%s\n",b.c_str());
		} 
		if(t != 0) printf("\n");
	}
	
	return 0;
}
