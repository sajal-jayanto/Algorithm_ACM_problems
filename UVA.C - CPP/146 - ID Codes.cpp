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
#define MAX 55

#define PI (2 *  acos(0.0))
#define eps 1e-7

using namespace std;

int main()
{
    int n;
    char ar[1000];
    while(gets(ar))
    {
        if(ar[0] == '#') break;
        if(next_permutation(ar, ar + strlen(ar))) printf("%s\n",ar);
        else printf("No Successor\n");
    }
    return 0;
}
