#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 100000

using namespace std;
char str[MAX];

int main()
{

    char *p;
    int one[10000], two[10000];
    while(gets(str))
    {
        int a = 0;
        int b = 0;
        p = strtok(str , " ");
        while(p != NULL)
        {
            one[a++] = atoi(p);
            p = strtok(NULL , " ");
        }
        gets(str);
        p = strtok(str , " ");
        while(p != NULL)
        {
            two[b++] = atoi(p);
            p = strtok(NULL , " ");
        }
        int first  = 0;
        int second = 0;
        for(int i = 0 ; i < a ; i++)
            for(int j = 0 ; j < b ; j++)
                if(one[i] == two[j]) { first++; break;}

        for(int i = 0 ; i < b ; i++)
            for(int j = 0 ; j < a ; j++)
                if(one[j] == two[i]) { second++; break;}

        if(a == first && a < b) printf("A is a proper subset of B\n");
        else if(b == second && a > b) printf("B is a proper subset of A\n");
        else if(a == b && first == a && second == b) printf("A equals B\n");
        else if(first == 0 && second == 0) printf("A and B are disjoint\n");
        else printf("I'm confused!\n");
    }

    return 0;
}
