#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define pf printf
#define sf scanf

using namespace std;

unordered_map < string , int > mp;
unordered_map < string , int >::iterator it;

void bfs(char *s , int len)
{
    mp[s] = 0;
    queue < string > Q;
    char last[15] , temp[15];
    int cnt ;
    Q.push(s);
    while(!Q.empty())
    {
        strcpy(last , Q.front().c_str());
        Q.pop();
        cnt = mp[last];
        for(int i = 0 ; i < len ; ++i)
        {
            for(int j = i + 1 ; j < len ; ++j)
            {
                strcpy(temp , last);
                reverse(temp + i , temp + j + 1);
                if(!mp.count(temp))
                {
                    Q.push(temp);
                    mp[temp] = cnt + 1;
                }
            }
        }
    }
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    bfs("abcdefghij" , 10);
    char one[20] , two[20] , three[20] , ch ;
    while(sf("%s %s" , one , two) == 2)
    {
        if(!strcmp(one , "*") && !strcmp(two , "*")) break ;
        ch = 'a';
        three[10] = '\0';
        for(int i = 0 ; i < 10 ; ++i)
        {
            for(int j = 0 ; j < 10 ; ++j)
            {
               if(one[i] == two[j]) { three[j] = ch; break; }
            }
            ++ch;
        }
        pf("%d\n" , mp[three]);
    }
    return 0;
}
