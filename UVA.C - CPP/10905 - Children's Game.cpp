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

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define MAX 55

using namespace std;

bool cmp(string a , string b)
{
    string x = a + b;
    string y = b + a;
    if(x > y) return true;
    return false;
}

int main()
{
	int t;
	string num[MAX];
	while(scanf("%d",&t) && t)
	{
		for(int i = 0 ; i < t; i++)
		{
			cin >> num[i];
		}
		sort(num , num + t ,cmp);
        for(int i = 0 ; i < t ; i++)
        {
            printf("%s",num[i].c_str());
        }
        printf("\n");
	}
    return 0;
}
