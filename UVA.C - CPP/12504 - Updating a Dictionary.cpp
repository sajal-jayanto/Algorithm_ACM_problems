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

int main()
{
    map <string , string> mymap;
    char s[10000],*p;
    string first,second,add,sub,mul;
    int t,len;
    bool flage;
    scanf("%d",&t);
    gets(s);
    while(t--)
    {
        scanf("%s",s);
        len = strlen(s) - 1;
        add = "+";sub = "*",mul = "-";flage = false;
        first.clear();second.clear();mymap.clear();
        p = strtok(s , "{:," );
        while(p != NULL)
        {
            if(first.empty()) first = p;
            else
            {
                second = p;
                mymap[first] = second;
                first.clear();
            }
            p = strtok(NULL , "}:," );
        }
        scanf("%s",s);
        len = strlen(s) - 1;
        p = strtok(s , "{:," );
        while(p != NULL)
        {
            if(first.empty()) first = p;
            else
            {
                second = p;
                if(mymap[first].empty())
                {
                    if(add == "+")
                    {
                        add = add + first;
                    }
                    else add = add + "," + first;
                    flage = true;
                    mymap[first] = "";
                }
                else if(mymap[first] != second)
                {
                    if(sub == "*")
                    {
                        sub = sub + first;
                    }
                    else sub = sub + "," + first;
                    flage = true;
                    mymap[first] = "";
                }
                else  mymap[first] = "";
                first.clear();
            }
            p = strtok(NULL , "}:," );
        }
        map<string,string>::iterator l;
        for(l = mymap.begin(); l != mymap.end();l++)
        {
            if(!l->second.empty())
            {
                first = l->first;
                if(mul == "-")
                {
                    mul = mul + first;
                }
                else mul = mul +  "," + first;
                flage = true;
            }
        }
        if(flage == false)
        {
            printf("No changes\n");
        }
        else
        {
            if(add != "+") printf("%s\n",add.c_str());
            if(mul != "-") printf("%s\n",mul.c_str());
            if(sub != "*") printf("%s\n",sub.c_str());
        }
        printf("\n");
    }
    return 0;
}
