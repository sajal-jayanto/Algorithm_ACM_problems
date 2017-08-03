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
	map<string,int>mymap;
	string sing[]  = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	int valu   []  = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	char str[100];
	int  num;
	string formet;
	for(int i = 1 ; i < 4000 ; i++)
	{
		num = i;
		string formet;
		for(int j = 12 ; j >= 0 && num ; j--)
		{
			while(num >= valu[j])
			{
				formet = formet + sing[j];
				num = num - valu[j];
			}
		}
		mymap[formet] = i;
	}
	formet = "";
	mymap[formet] = 0;
	while(gets(str))
	{
		if(str[0] == '\0')
		{
			printf("0\n");
			continue;
		}
		formet = str;
		if(mymap[formet] != 0) printf("%d\n",mymap[formet]);
		else printf("This is not a valid number\n");
	}
 	return 0;
}

