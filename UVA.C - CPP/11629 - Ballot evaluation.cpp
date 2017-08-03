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
	int p,g,count = 0;
	char name[10000],*pointer;
	int pr,ps,sum;
	string s,sing;
	map<string,int>mymap;
	scanf("%d %d",&p,&g);
	gets(name);
	for(int i = 0 ; i < p ; i++)
	{
		scanf("%s %d.%d",name,&pr,&ps);
		s = name;
		mymap[s] = (pr * 10) + ps;
	}
	gets(name);
	for(int i = 0 ; i < g ; i++)
	{
		gets(name);
		pr = 0;
		pointer = strtok(name," ");
		while(pointer != NULL)
		{
			s = pointer;
			if(mymap[s] != 0) pr = pr + mymap[s]; 
			if(s == ">" || s == "<" || s == "<=" || s == ">=" || s == "=") sing = s; 
			pointer = strtok(NULL," ");
		}
		sum = atof(s.c_str()) * 10;
		if(sing == "=")
		{
			if(pr == sum) printf("Guess #%d was correct.\n",++count);
			else printf("Guess #%d was incorrect.\n",++count);
		}
		else if(sing == ">=")
		{
			if(pr >= sum) printf("Guess #%d was correct.\n",++count);
			else printf("Guess #%d was incorrect.\n",++count);
		}
		else if(sing == "<=")
		{
			if(pr <= sum) printf("Guess #%d was correct.\n",++count);
			else printf("Guess #%d was incorrect.\n",++count);
		}
		else if(sing == ">")
		{
			if(pr > sum)printf("Guess #%d was correct.\n",++count);
			else printf("Guess #%d was incorrect.\n",++count);
		}
		else if(sing == "<")
		{
			if(pr < sum) printf("Guess #%d was correct.\n",++count);
			else printf("Guess #%d was incorrect.\n",++count);
		}
	}	
	return 0;
}

