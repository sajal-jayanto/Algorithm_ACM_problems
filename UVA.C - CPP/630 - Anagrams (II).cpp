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
#define MAX 1010

using namespace std;
bool find_it(int a);
string str[MAX];
int len[MAX];
string temp;
vector < string > print;
int ab[80];
int abc[80];

int main()
{
    //freopen("input.txt","r", stdin);
    int t, n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){ cin >> str[i]; len[i] = str[i].length(); }
        //for(int i = 0 ; i < n ; i++) cout <<  str[i] << "\n";
        while(cin >> temp && temp != "END")
        {
            int len1 = temp.length();
            memset(ab , 0 , sizeof(ab));
            for(int i = 0 ; temp[i] ; i++) ab[temp[i] - 'A']++;
            for(int i = 0 ; i < n ; i++)
            {
                if(len[i] == len1)
                {
                    if(find_it(i)) print.push_back(str[i]);
                }
            }
            printf("Anagrams for: %s\n",temp.c_str());
            if(print.size() == 0) printf("No anagrams for: %s\n",temp.c_str());
            else
            {
                int c = 0;
                for(int i = 0 ; i < print.size() ; i++) printf("%3d) %s\n",++c,print[i].c_str());
                print.clear();
            }
        }
        if(t) printf("\n");
    }
    return 0;
}

bool find_it(int a)
{
    memset(abc , 0 , sizeof(abc));
    for(int i = 0 ; str[a][i] ; i++) abc[str[a][i] - 'A']++;
    for(int i = 0 ; i < 80 ; i++) if(abc[i] != ab[i]) return false;
    return true;
}
