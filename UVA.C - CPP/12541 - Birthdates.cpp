#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define MAX 105

using namespace std;

struct node{

    char name[20];
    long long total;

} person[MAX];

bool cmp(const node &a , const node &b)
{
    if(a.total < b.total) return true;
    else return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    char str[MAX];
    int t,day,mon,year;
    scanf("%d",&t);
    gets(str);
    for(int i = 0 ; i < t ; i++)
    {
        gets(str);
        sscanf(str, "%s" "%d" "%d" "%d", person[i].name , &day , &mon , &year);
        person[i].total = day + (mon * 31) + (year * 12 * 31);
    }
    sort(person , person + t , cmp);

    printf("%s\n%s\n",person[t - 1].name,person[0].name);
}


