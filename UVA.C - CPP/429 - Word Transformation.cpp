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

using namespace std;
map < string , int > memo;
map < string , vector < string > > mymap;
map < string , vector < string > >::iterator it;
void BFS(string a , string b , map < string , vector < string > > mymap);

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t;
    scanf("%d",&t);
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        string temp, s;
        while(cin >> temp && temp != "*")
        {
            mymap[temp];
            for(it = mymap.begin() ; it != mymap.end() ; it++)
            {
                s = (*it).first;
                int cnt = 0;
                for(int i = 0 ; s[i] && cnt < 2 ; i++) if(s[i] != temp[i]) cnt++;
                if(cnt == 1) mymap[temp].push_back(s), mymap[s].push_back(temp);
            }
        }
        cin.ignore();
        while(getline(cin , temp))
        {
            if(temp.empty()) break;
            int n = temp.find(" ");
            s = temp.substr(0 , n);
            temp = temp.substr(n + 1 , temp.size());
            BFS(s  , temp , mymap);
            printf("%s %s %d\n",s.c_str() ,temp.c_str(), memo[temp]);
        }
        mymap.clear();
        if(t) printf("\n");
    }
    return 0;
}


void BFS(string a , string b , map < string , vector < string > > mymap)
{
    memo.clear();
    queue < string > Q;
    Q.push(a);
    memo[a] = 0;
    while(!Q.empty())
    {
        string k = Q.front();
        Q.pop();
        if(k == b) return ;
        int len = mymap[k].size();
        for(int i = 0 ; i < len ; i++)
        {
            string l = mymap[k][i];
            if(memo[l] == 0)
            {
                memo[l] = memo[k] + 1;
                Q.push(l);
            }
        }
    }
}
