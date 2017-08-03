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


using namespace std;


int consonant(char);

int main()
{
    //freopen("input.txt","r",stdin);
    char frist[500];
    char second[500];
    string s;
    map < string , int > mymap;
    map < string , string > mymap1;
    int n,t,len;
    scanf("%d %d",&n,&t);
    gets(frist);
    while(n--)
    {
        scanf("%s %s",frist,second);
        s = frist;
        mymap[s]++;
        mymap1[s] = second;
    }
    bool flage;
    while(t--)
    {
        flage = true;
        scanf("%s",frist);
        s = frist;
        len = strlen(frist) - 1;
        if(mymap[s] != 0)
        {
            printf("%s\n",mymap1[s].c_str());
            flage = false;
        }
        else if(frist[len] == 'y' && consonant(frist[len - 1]) == 0)
        {
            for(int i = 0 ; i < len ; i++) printf("%c",frist[i]);
            printf("ies\n");
            flage = false;
        }
        else if(frist[len] == 'o' ||frist[len] == 's'|| frist[len] == 'h' || frist[len] == 'x')
        {
            if(frist[len] == 'h' && (frist[len] == 'c' || frist[len] == 's'))
            {
                printf("%ses\n",frist);
                flage = false;
            }
            if(flage)
            {
                printf("%ses\n",frist);
                flage = false;
            }
        }
        if(flage) printf("%ss\n",frist);
    }
    return 0;
}

int consonant(char ch)
{
    if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') return 0;
    return 1;
}
