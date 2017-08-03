#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char str[300];
    bool flage;
    stack < char > S;
    while(gets(str))
    {
        flage = true;
        for(int i = strlen(str) - 1 ; i >= 0 ; i--)
        {
            if(str[i] >= 'p' && str[i] <= 'z') S.push(str[i]);
            else if(str[i] == 'N')
            {
                if(S.size() == 0) flage = false;
            }
            else if(str[i] == 'C' || str[i] == 'D'|| str[i] == 'E' || str[i] == 'I' )
            {
                if(S.size() >= 2) S.pop();
                else flage = false;
            }
        }
        if(S.size() == 1 && flage == true) printf("YES\n");
        else printf("NO\n");
        while(!S.empty()) S.pop();
    }
    return 0;
}
