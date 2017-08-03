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
struct node
{
    int num;
    string s;
}print[105];
map < string , int > mymap;
int k;

bool cmp(const node &a , const node &b)
{
    if(a.num < b.num) return true;
    return false;
}

int main()
{
    freopen("input.txt", "r",  stdin);
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
        k = 0;
        string temp;
        getline(cin , temp);
        transform(temp.begin(), temp.end(),temp.begin(),::toupper);
        printf("%s\n",temp.c_str());
        int x ,y ,z, c;
        cin >> x >> y >> z;
        while(x--)
        {
            getchar();
            cin >> temp >> c;
            mymap[temp] = c;
        }
        getchar();
        while(y--)
        {
            getline(cin , temp);
            cin >> c;
            getchar();
            string s ;
            int n, sum = 0;
            while(c--)
            {
                cin >> s >> n;
                getchar();
                sum = sum + (mymap[s] * n);
            }
            if(sum <= z)
            {
                print[k].num = sum;
                print[k].s = temp;
                k++;
            }
        }
        if(k == 0) printf("Too expensive!\n");
        else
        {
            sort (print , print + k , cmp);
            for(int i = 0 ; i < k ; i++) printf("%s\n",print[i].s.c_str());
        }
        mymap.clear();
        printf("\n");
    }
    return 0;
}

