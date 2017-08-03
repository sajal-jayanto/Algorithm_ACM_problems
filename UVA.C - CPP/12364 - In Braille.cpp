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

int find_out(string s);

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char ar[5][10000];
    int t,len;
    char ch;
    string s;
    while(scanf("%d",&t) && t)
    {
        gets(ar[0]);
        ch = getchar();
        gets(ar[0]);
        if(ch == 'S')
        {
            gets(ar[0]);
            len = strlen(ar[0]);
            for(int i = 0 ; i < len ; i++)
            {
                switch(ar[0][i])
                {
                    case '1': { printf("*."); break; }
                    case '2': { printf("*."); break; }
                    case '3': { printf("**"); break; }
                    case '4': { printf("**"); break; }
                    case '5': { printf("*."); break; }
                    case '6': { printf("**"); break; }
                    case '7': { printf("**"); break; }
                    case '8': { printf("*."); break; }
                    case '9': { printf(".*"); break; }
                    case '0': { printf(".*"); break; }
                }
                if( i != len - 1) printf(" ");
            }
            printf("\n");
            for(int i = 0 ; i < len ; i++)
            {
                switch(ar[0][i])
                {
                    case '1': { printf(".."); break; }
                    case '2': { printf("*."); break; }
                    case '3': { printf(".."); break; }
                    case '4': { printf(".*"); break; }
                    case '5': { printf(".*"); break; }
                    case '6': { printf("*."); break; }
                    case '7': { printf("**"); break; }
                    case '8': { printf("**"); break; }
                    case '9': { printf("*."); break; }
                    case '0': { printf("**"); break; }
                }
                if( i != len - 1) printf(" ");
            }
            printf("\n");
            for(int i = 0 ; i < len ; i++)
            {
                printf("..");
                if( i != len - 1) printf(" ");
            }
            printf("\n");
        }
        else
        {
            for(int i = 0 ; i < 3 ; i++) gets(ar[i]);
            len = strlen(ar[0]) - 1;
            for(int i = 0 ; i < len ; i++)
            {
                if(ar[0][i] != ' ' && ar[0][i + 1] != ' ')
                {
                    s = s + ar[0][i] + ar[0][i + 1] + ar[1][i] + ar[1][i + 1];
                    printf("%d",find_out(s));
                    s.clear();
                }
            }
            printf("\n");
        }
    }

    return 0;
}

int find_out(string s)
{

    if(s == "*...") return 1;
    else if(s == "*.*.") return 2;
    else if(s == "**..") return 3;
    else if(s == "**.*") return 4;
    else if(s == "*..*") return 5;
    else if(s == "***.") return 6;
    else if(s == "****") return 7;
    else if(s == "*.**") return 8;
    else if(s == ".**.") return 9;
    else if(s == ".***") return 0;
}
