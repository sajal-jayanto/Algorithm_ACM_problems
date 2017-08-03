#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

char dic[105][8];
char temp[8];
set < string > myset;
void find_it(int a);
int main()
{
    //freopen("input.txt", "r", stdin);
    int k = 0;
    while(true)
    {
        scanf("%s",dic[k]);
        if(strcmp(dic[k] , "XXXXXX") == 0) break;
        k++;
    }
    while(true)
    {
        scanf("%s",temp);
        if(strcmp(temp , "XXXXXX") == 0) break;
        myset.clear();
        int len = strlen(temp);
        for(int i = 0 ; i < k ; i++) if(len == strlen(dic[i])) find_it(i);
        if(myset.empty()) printf("NOT A VALID WORD\n");
        else for(set < string >::iterator it = myset.begin() ; it != myset.end() ; it++) printf("%s\n",(*it).c_str());
        printf("******\n");
    }
    return 0;
}

void find_it(int a)
{

    int abc[26];
    memset(abc , 0 , sizeof(abc));
    for(int i = 0 ; dic[a][i] ; i++) abc[dic[a][i] - 'a']++;
    int ab[26];
    memset(ab , 0 , sizeof(ab));
    for(int i = 0 ; temp[i] ; i++) ab[temp[i] - 'a']++;
    for(int i = 0 ; i < 26 ; i++) if(abc[i] != ab[i]) return ;
    myset.insert(dic[a]);
}
