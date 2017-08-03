#include <bits/stdc++.h>

using namespace std;


#define sf scanf
#define pf printf
#define MAX 1000010

map < pair < string , string > , string > mp;
map < pair < string , string > , string > ::iterator x ;
string str;

bool is_hehe(char *s , int len)
{
    for(int i = 0 ; i < len ; i = i + 2)
    {
        if(s[i] != 'H' && s[i] != 'h') return false;
        if(s[i + 1] != 'E' && s[i + 1] != 'e') return false;
    }
    return true;
}

int main()
{
   // freopen("tem.txt" , "r" , stdin);
    char *p ;
    double te;
    string a , b , c ;
    int total , len , cnt ;
    while(getline(cin , str))
    {
        cnt = 0;
        c.clear();
        p = strtok(&str[0] , " -?.!>:");
        while(p != NULL)
        {
            if(cnt == 0) a = p;
            else if(cnt == 1) b = p;
            else c = c + " " + p;
            p = strtok(NULL , " -?.!>:");
            ++cnt;
        }
        if(a > b) swap(a , b);
        mp[make_pair(a , b)] = c ;
    }
    cnt = 0;
    total = (int) mp.size();
    for(x = mp.begin() ; x != mp.end() ; x++)
    {
        str = x->second ;
        p = strtok(&str[0] , " -?.!>:");
        while(p != NULL)
        {
            len = strlen(p);
            if(len % 2 == 0 && len >= 4)
            {
                if(is_hehe(p , len))
                {
                    ++cnt;
                    break ;
                }
            }
            p = strtok(NULL , " .?!,");
        }
    }
    len = (cnt * 100) / total;
    te = double((cnt * 100.00) / total);
    te = double(te - len);
    if(te >= 0.5) pf("%d%%\n" , len + 1);
    else pf("%d%%\n" , len);
    return 0;
}
