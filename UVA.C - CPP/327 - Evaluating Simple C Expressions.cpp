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

char str[10000];
char ar[10000];

int main()
{
   // freopen("output.txt","w",stdout);
    int sum,k;
    char ch;
    map < char , int > mapa;
    map < char , int > mapb;
    while(gets(ar))
    {
        k = 0;
        for(int i = 0 ; ar[i] ; i++)
        {
            if(ar[i] != ' ') str[k++] = ar[i];
        }
        str[k] = '\0';
        printf("Expression: %s\n",ar);
        for(int i = 0 ; i < 26 ; i++)
        {
            ch = i + 97;
            mapb[ch] = i + 1;
        }
        for(int i = 0 ; str[i] ; i++)
        {
            if(islower(str[i]) != 0)
            {
                if(str[i - 1] == '+' && str[i - 2] == '+')
                {
                    str[i - 1] = '?';
                    str[i - 2] = '?';
                    if(mapa[str[i]] == 0) mapa[str[i]] = (str[i] - 96) + 1;
                    else mapa[str[i]]++;
                    mapb[str[i]] = mapa[str[i]];
                }
                else if(str[i - 1] == '-' && str[i - 2] == '-')
                {
                    str[i - 1] = '?';
                    str[i - 2] = '?';
                    if(mapa[str[i]] == 0) mapa[str[i]] = (str[i] - 96) - 1;
                    else mapa[str[i]]--;
                    mapb[str[i]] = mapa[str[i]];
                }
                else if(str[i + 1] == '+' && str[i + 2] == '+')
                {
                    str[i + 1] = '?';
                    str[i + 2] = '?';
                    if(mapa[str[i]] == 0) mapa[str[i]] = (str[i] - 96) + 1;
                    else mapa[str[i]]++;
                }
                else if(str[i + 1] == '-' && str[i + 2] == '-')
                {
                    str[i + 1] = '?';
                    str[i + 2] = '?';
                    if(mapa[str[i]] == 0) mapa[str[i]] = (str[i] - 96) - 1;
                    else mapa[str[i]]--;
                }
                else mapa[str[i]] = (str[i] - 96);
            }
        }
        sum = 0;
        ch = '?';
        for(int j = 0 ; str[j] ; j++)
        {
            if(str[j] == '+' || str[j] == '-') ch = str[j];
            else if(islower(str[j])!= 0)
            {
                if(ch == '?') sum = mapb[str[j]];
                else
                {
                    if(ch == '+') sum = sum  + mapb[str[j]];
                    if(ch == '-') sum = sum  - mapb[str[j]];
                    ch = '?';
                }
            }
        }
        printf("    value = %d\n",sum);
        for(map < char , int >::iterator it = mapa.begin() ; it != mapa.end() ; it++)
        {
            printf("    %c = %d\n",it->first,it->second);
        }
        mapb.clear();
        mapa.clear();
    }
    return 0;
}
