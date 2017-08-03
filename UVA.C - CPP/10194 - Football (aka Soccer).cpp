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
#define MAX 35
#define fileR freopen("input.txt", "r" , stdin)

using namespace std;

int conv(string s);
int find_it(string a);
void updet(string one , string two , int a , int b);

struct node{

    char name[100];
    int point;
    int gdef;
    int play;
    int win;
    int drow;
    int los;
    int gg;
    int gh;

}team[MAX];
int y;

bool cmp(const node &a , const node &b)
{
    if(a.point > b.point) return true;
    else if(a.point == b.point && a.win > b.win) return true;
    else if(a.point == b.point && a.win == b.win && a.gdef > b.gdef) return true;
    else if(a.point == b.point && a.win == b.win && a.gdef == b.gdef && a.gg > b.gg) return true;
    else if(a.point == b.point && a.win == b.win && a.gdef == b.gdef && a.gg == b.gg && a.play < b.play ) return true;
    else if(a.point == b.point && a.win == b.win && a.gdef == b.gdef && a.gg == b.gg && a.play == b.play && strcasecmp(a.name , b.name) < 0) return true;
    else return false;
}

int main()
{
    //fileR;
    //freopen("output.txt", "w" , stdout);
    int t, n;
    string temp , s;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        getline(cin , temp);
        printf("%s\n", temp.c_str());
        scanf("%d", &y);
        getchar();
        for(int i = 0 ; i < y ; i++)
        {
            gets(team[i].name);
            team[i].point = 0;
            team[i].gdef = 0;
            team[i].play = 0;
            team[i].win = 0;
            team[i].drow = 0;
            team[i].los = 0;
            team[i].gg = 0;
            team[i].gh = 0;
        }
        string teama , teamb;
        int a , b;
        scanf("%d", &n);
        getchar();
        int x = n;
        while(x--)
        {
            s.clear();
            int cnt = 0;
            getline(cin , temp);
            for(int i = 0 ; temp[i] ; i++)
            {
                if(temp[i] == '#' || temp[i] == '@')
                {
                    if(cnt == 0) { teama = s;}
                    else if(cnt == 1) { a = conv(s);}
                    else if(cnt == 2) { b = conv(s);}
                    s.clear();
                    cnt++;
                }
                else s = s + temp[i];
            }
            teamb = s;
            updet(teama, teamb,a ,b);
        }
        for(int i = 0 ; i < y ; i++)
        {
            team[i].point = (team[i].win * 3) + team[i].drow;
            team[i].gdef = team[i].gg - team[i].gh;
            team[i].play = team[i].win+team[i].drow+team[i].los;
        }
        sort ( team , team + y, cmp);
        for(int i = 0 ; i < y ; i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i + 1,team[i].name ,team[i].point,
            team[i].play, team[i].win, team[i].drow , team[i].los, team[i].gdef,team[i].gg , team[i].gh);
        }
        if(t) printf("\n");
    }
    return 0;
}

int conv(string s)
{
    int a = 0;
    for(int i = 0 ; i < s.size() ; i++) a = (a * 10) + (s[i] - 48);
    return a;
}

void updet(string one , string two , int a , int b)
{
   // printf("%s %s\n",one.c_str() , two.c_str());
    int k;
    if(a == b)
    {
        k = find_it(one);
        team[k].drow++;
        team[k].gg += a;
        team[k].gh += b;
        k = find_it(two);
        team[k].drow++;
        team[k].gg += a;
        team[k].gh += b;
    }
    else if(a > b)
    {
        k = find_it(one);
        team[k].win++;
        team[k].gg += a;
        team[k].gh += b;
        k = find_it(two);
        team[k].los++;
        team[k].gg += b;
        team[k].gh += a;
    }
    else
    {
        k = find_it(one);
        team[k].los++;
        team[k].gg += a;
        team[k].gh += b;
        k = find_it(two);
        team[k].win++;
        team[k].gg += b;
        team[k].gh += a;
    }
}

int find_it(string a)
{

    for(int i = 0 ; i < y ; i++) if(a == team[i].name) return i;
}
