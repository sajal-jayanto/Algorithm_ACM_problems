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
#define MAX 1005

using namespace std;

string str[MAX];
set < string > myset;
string temp;
int k = 0;
bool find_it(int a);
int abc[26];

int main()
{
    //freopen("input.txt","r",stdin);
    while(cin >> temp)
    {
        if(temp[0] == '#') break;
        str[k++] = temp;
    }
    for(int i = 0 ; i < k ; i++)
    {
        int len = str[i].length();
        bool f = false;
        memset(abc , 0 , sizeof(abc));
        for(int j = 0 ; str[i][j] ; j++) abc[tolower(str[i][j]) - 'a']++;
        for(int j = 0 ; j < k ; j++)
        {
            if(len == str[j].length() && i != j)
            {
                if(find_it(j)){ f = true; break;}
            }
        }
        if(!f) myset.insert(str[i]);
    }
    for(set < string >::iterator it = myset.begin() ; it != myset.end() ; it++) printf("%s\n",(*it).c_str());
    return 0;
}

bool find_it(int a)
{
    int ab[26];
    memset(ab , 0 , sizeof(ab));
    for(int i = 0 ; str[a][i] ; i++) ab[tolower(str[a][i]) - 'a']++;
    for(int i = 0 ; i < 26 ; i++) if(ab[i] != abc[i]) return false;
    return true;
}

