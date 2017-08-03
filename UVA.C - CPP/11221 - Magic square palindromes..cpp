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
#define MAX 10010

using namespace std;

char str[MAX];

int main()
{

    char ch;
    int t,k,cc = 0;
    bool flage;
    stack < char > mystack;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        k = 0;
        while(ch = getchar())
        {
            if(ch == '\n') break;
            if(islower(ch) != 0) str[k++] = ch;
        }
        str[k] = '\0';
        printf("Case #%d:\n",++cc);
        if(sqrt(k) != ceil(sqrt(k)))
        {
            printf("No magic :(\n");
            continue;
        }
        flage = true;
        int i;
        for(i = 0 ; i < k / 2 ; i++) mystack.push(str[i]);
        if(k % 2 != 0) mystack.push(str[i]);
        for( ; i < k ; i++)
        {
            if(mystack.top() != str[i])
            {
                printf("No magic :(\n");
                flage = false;
                break;
            }
            mystack.pop();
        }
        if(flage) printf("%d\n",(int)sqrt(k));
    }
    return 0;
}
