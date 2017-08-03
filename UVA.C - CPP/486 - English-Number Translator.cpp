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
#define MAX 5000010

#define PI (2 *  acos(0.0))
#define eps 1e-7
void is_prime();

using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);
	map <string,int> mymap;
	mymap["zero"] = 0;        mymap["one"] = 1;       mymap["two"] = 2;
	mymap["three"] = 3;       mymap["four"] = 4;      mymap["five"] = 5;
    mymap["six"] = 6;         mymap["seven"] = 7;     mymap["ten"] = 10;
	mymap["eight"] = 8;       mymap["nine"] = 9;      mymap["thirteen"] = 13;
	mymap["eleven"] = 11;     mymap["twelve"] = 12;   mymap["sixteen"] = 16;
	mymap["fourteen"] = 14;   mymap["fifteen"] = 15;  mymap["nineteen"] = 19;
	mymap["seventeen"] = 17;  mymap["eighteen"] = 18; mymap["forty"] = 40;
	mymap["twenty"] = 20;     mymap["thirty"] = 30;   mymap["seventy"] = 70;
	mymap["fifty"] = 50;      mymap["sixty"] = 60;    mymap["eighty"] = 80;
    mymap["ninety"] = 90;
	char ar[1600];
	char *p;
	string s;
	long long ans,M,T,H;
	while(gets(ar))
	{
	    ans = M = T = 0;
		p = strtok(ar," ");
		while(p != NULL)
		{
			s = p;
			if(mymap[s] != 0) ans = ans + mymap[s];
			else if(s == "negative") printf("-");
			else if(s == "hundred")  ans =  ans * 100;
			else if(s == "thousand")
            {
                T = ans * 1000;
                ans = 0;
            }
			else if(s == "million")
            {
                M = ans * 1000000;
                ans = 0;
            }
            p = strtok(NULL ," ");
		}
        ans = ans + M + T;
		printf("%lld\n",ans);
	}
	return 0;
}
