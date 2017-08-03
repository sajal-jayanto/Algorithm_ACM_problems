#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<string>
#include<algorithm>


using namespace std;

int main()
{

    map<string,int> mymap;
    char name1[50],name2[150];
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%[^\n]s",name1,name2);
        s = name1;
        mymap[s]++;
    }
    map<string ,int>::iterator i;
    for(i = mymap.begin(); i != mymap.end(); i++)
    {
        printf("%s %d\n",i->first.c_str(),i->second);
    }
    return 0;
}
