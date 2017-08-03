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
    set<string>res;
    string s;
    while(cin >> s)
    {
        string p = "";
        int l=s.size();
        for(int i=0;i<=l;i++){
           if(isalpha(s[i])){
            p+=tolower(s[i]);
           }
           else if(p!=""){
           res.insert(p);
           p="";
           }
        }
    }
    for (std::set<string>::iterator it=res.begin(); it!=res.end();it++)
    cout<<*it<<endl;

    return 0;
}
