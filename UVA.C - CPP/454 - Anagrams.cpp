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
#define MAX 105

using namespace std;
bool find_it(int a);
string str[MAX];
int abc[80];
int ab[80];
multiset < string > print;
multiset < string > have;
multiset < string >::iterator it;

int main()
{
    //freopen("input.txt" ,"r" , stdin);
    int t;
    scanf("%d", &t);
    string temp;
    getchar();
    getchar();
    while(t--)
    {
        int k = 0;
        while(getline(cin , temp))
        {
            if(temp[0] == '\0') break;
            str[k++] = temp;
        }
        for(int i = 0 ; i < k ; i++)
        {
            memset(abc , 0 , sizeof(abc));
            for(int j = 0 ; str[i][j] ; j++) if(isalpha(str[i][j]) != 0) abc[str[i][j] - 'A']++;
            for(int j = 0 ; j < k ; j++)
            {
                if(i != j)
                {
                    if(find_it(j))
                    {
                        temp.clear();
                        have.insert(str[i]);
                        have.insert(str[j]);
                        it = have.begin();
                        temp = (*it) + " = ";
                        it++;
                        temp = temp + (*it);
                        have.clear();
                        if(print.empty()) print.insert(temp);
                        else
                        {
                            it = have.find(temp);
                            if(it == have.end()) print.insert(temp);
                        }
                    }
                }
            }
        }
        for(it = print.begin() ; it != print.end() ; it++) printf("%s\n",(*it).c_str()) ,it++;
        print.clear();
        if(t) printf("\n");
    }
    return 0;
}


bool find_it(int a)
{
    memset(ab , 0 , sizeof(ab));
    for(int i = 0 ; str[a][i] ; i++)  if(isalpha(str[a][i]) != 0) ab[str[a][i] - 'A']++;
    for(int i = 0 ; i < 80 ; i++) if(ab[i] != abc[i]) return false;
    return true;
}
