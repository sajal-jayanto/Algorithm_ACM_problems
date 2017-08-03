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
#define MAX 100010


using namespace std;

char do_it(string s);

char str[5 * MAX];
int num[50];
char simb[50];

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t = 0,len,valu,k,p;
    string s;
    char str[5][100];
    while(true)
    {
        if(t != 0) gets(str[0]);
        t++;
        for(int i = 0 ; i < 5 ; i++) gets(str[i]);
        if((strlen(str[0]) == 3) && (strcmp(str[0] , "000") == 0)) break;
        len = strlen(str[0]) - 2;
        valu = 0;
        k = 0;
        p = 0;
        for(int i = 0 ; i < len ; i++)
        {
            if(str[0][i] != ' ' && str[0][i + 1] != ' ' && str[0][i + 2] != ' ')
            {
                for(int j = 0 ; j < 5 ; j++)
                {
                    s = s + str[j][i] + str[j][i + 1] + str[j][i + 2];
                }
                char c = do_it(s);
                if(c == '+' || c == '-' || c == '*' || c == '/')
                {
                    num[p++] = valu;
                    simb[k++] = c;
                    valu = 0;
                }
                else valu = (valu * 10) + (c - 48);
                s.clear();
            }
        }
        num[p++] = valu;
        if(simb[0] == '+') valu = num[0] + num[1];
        else if(simb[0] == '-') valu = num[0] - num[1];
        else if(simb[0] == '*') valu = num[0] * num[1];
        else if(simb[0] == '/') valu = num[0] / num[1];
        for(int i = 1 ; i < k ; i++)
        {
            if(simb[i] == '+') valu = valu + num[i +1 ];
            else if(simb[i] == '-') valu = valu - num[i + 1];
            else if(simb[i] == '*') valu = valu * num[i + 1];
            else if(simb[i] == '/') valu = valu / num[i + 1];
        }
        k = 0;
        while(valu)
        {
            simb[k++] = (valu % 10) + 48;
            valu = valu / 10;
        }
        reverse(simb , simb + k);
        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                switch(simb[j])
                {
                    case '1':
                    {
                        if(i == 0) printf(".0.");
                        else if(i == 1) printf(".0.");
                        else if(i == 2) printf(".0.");
                        else if(i == 3) printf(".0.");
                        else if(i == 4) printf(".0.");
                        break;

                    }
                    case '2':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("..0");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("0..");
                        else if(i == 4) printf("000");
                        break;
                    }
                    case '3':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("..0");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("..0");
                        else if(i == 4) printf("000");
                        break;
                    }
                    case '4':
                    {
                        if(i == 0) printf("0.0");
                        else if(i == 1) printf("0.0");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("..0");
                        else if(i == 4) printf("..0");
                        break;
                    }
                    case '5':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("0..");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("..0");
                        else if(i == 4) printf("000");
                        break;
                    }
                    case '6':
                    {
                        if(i == 0) printf("0..");
                        else if(i == 1) printf("0..");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("0.0");
                        else if(i == 4) printf("000");
                        break;
                    }
                    case '7':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("..0");
                        else if(i == 2) printf("..0");
                        else if(i == 3) printf("..0");
                        else if(i == 4) printf("..0");
                        break;
                    }
                    case '8':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("0.0");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("0.0");
                        else if(i == 4) printf("000");
                        break;
                    }
                    case '9':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("0.0");
                        else if(i == 2) printf("000");
                        else if(i == 3) printf("..0");
                        else if(i == 4) printf("..0");
                        break;
                    }
                    case '0':
                    {
                        if(i == 0) printf("000");
                        else if(i == 1) printf("0.0");
                        else if(i == 2) printf("0.0");
                        else if(i == 3) printf("0.0");
                        else if(i == 4) printf("000");
                        break;
                    }
                }
                if(j != k - 1) printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

char do_it(string s)
{
    if(s == "0000.00.00.0000") return '0';
    else if(s == ".0..0..0..0..0.") return '1';
    else if(s == "000..00000..000") return '2';
    else if(s == "000..0000..0000") return '3';
    else if(s == "0.00.0000..0..0") return '4';
    else if(s == "0000..000..0000") return '5';
    else if(s == "0..0..0000.0000") return '6';
    else if(s == "000..0..0..0..0") return '7';
    else if(s == "0000.00000.0000") return '8';
    else if(s == "0000.0000..0..0") return '9';
    else if(s == ".0..0.000.0..0.") return '+';
    else if(s == "......000......") return '-';
    else if(s == "0.00.0.0.0.00.0") return '*';
    else if(s == ".0....000....0.") return '/';
}

