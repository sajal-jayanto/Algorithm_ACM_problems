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

struct node {
    char up;
    char down;
} node[32];

int main()
{
    char str[5000];
    string s;
    gets(str);
    for(int i = 0 ; i < 32 ; i++) node[i].up = str[i];
    gets(str);
    for(int i = 0 ; i < 32 ; i++) node[i].down = str[i];
    map<string,int> mymap;
    mymap["00000"] = 1;  mymap["00001"] = 2;  mymap["00010"] = 3;  mymap["00011"] = 4;
    mymap["00100"] = 5;  mymap["00101"] = 6;  mymap["00110"] = 7;  mymap["00111"] = 8;
    mymap["01000"] = 9;  mymap["01001"] = 10; mymap["01010"] = 11; mymap["01011"] = 12;
    mymap["01100"] = 13; mymap["01101"] = 14; mymap["01110"] = 15; mymap["01111"] = 16;
    mymap["10000"] = 17; mymap["10001"] = 18; mymap["10010"] = 19; mymap["10011"] = 20;
    mymap["10100"] = 21; mymap["10101"] = 22; mymap["10110"] = 23; mymap["10111"] = 24;
    mymap["11000"] = 25; mymap["11001"] = 26; mymap["11010"] = 27; mymap["11011"] = 28;
    mymap["11100"] = 29; mymap["11101"] = 30; mymap["11110"] = 31; mymap["11111"] = 32;
    while(gets(str))
    {
        int len = strlen(str);
        int count = 0;
        int n;
        bool flage = false;
        s.clear();
        for(int i = 0 ; i < len ; i++)
        {
            if(count != 0 && count % 5 == 0)
            {
                n = mymap[s] - 1;
                if(n == 27) flage = false;
                else if(n == 31) flage = true;
                if(flage && n != 27 && n != 31) printf("%c",node[n].down);
                else if(n != 27 && n != 31) printf("%c",node[n].up);
                s.clear();
                s = s + str[i];
                count++;
            }
            else
            {
                s = s + str[i];
                count++;
            }
        }
        n = mymap[s] - 1;
        if(flage && n != 27 && n != 31) printf("%c",node[n].down);
        else if(n != 27 && n != 31) printf("%c",node[n].up);
        printf("\n");
    }
    return 0;
}
