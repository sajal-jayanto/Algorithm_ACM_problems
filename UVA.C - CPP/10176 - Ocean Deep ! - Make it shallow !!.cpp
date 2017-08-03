#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAX 131071

using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);
    int num;
    char ch;
    while(cin >> ch)
    {
        num = 0 ;
        num = num  + (ch - 48);
        while(cin >> ch)
        {
            if(ch == '#') break;
            num = num  * 2;
            num =  num + (ch - 48);
            num = num % MAX;
        }
        if(num == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
