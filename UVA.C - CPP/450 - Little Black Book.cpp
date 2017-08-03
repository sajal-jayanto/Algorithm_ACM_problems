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
#define MAX 3600
#define fileR freopen("input.txt", "r" , stdin)
#define fileW freopen("output.txt", "w" , stdout)

using namespace std;

struct node {

    string titel;
    string firstname;
    string lastname;
    string home;
    string deparment;
    string Hphon;
    string Wphon;
    string Cbox;

}person[MAX];
int k = 0;

bool cmp(const node &a , const node &b)
{
    return a.lastname < b.lastname;
}

int main()
{
    //fileR;
    int t;
    string Dtemp, line;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        getline(cin , Dtemp);
        while(getline(cin , line) && !line.empty())
        {
            int cnt = 0;
            string s;
            s.clear();
            for(int i = 0 ; line[i] ; i++)
            {
                if(line[i] == ',')
                {
                    if(cnt == 0) person[k].titel = s;
                    else if(cnt == 1) person[k].firstname = s;
                    else if(cnt == 2) person[k].lastname = s;
                    else if(cnt == 3) person[k].home = s;
                    else if(cnt == 4) person[k].Hphon = s;
                    else if(cnt == 5) person[k].Wphon = s;
                    cnt++;
                    s.clear();
                }
                else s = s + line[i];
            }
            person[k].Cbox = s;
            person[k].deparment = Dtemp;
            k++;
        }
    }
    sort(person , person + k , cmp);
    for(int i = 0 ; i < k  ; i++)
    {
        printf("----------------------------------------\n");
        printf("%s %s %s\n",person[i].titel.c_str() ,person[i].firstname.c_str(),person[i].lastname.c_str());
        printf("%s\n", person[i].home.c_str());
        printf("Department: %s\n", person[i].deparment.c_str());
        printf("Home Phone: %s\n", person[i].Hphon.c_str());
        printf("Work Phone: %s\n", person[i].Wphon.c_str());
        printf("Campus Box: %s\n", person[i].Cbox.c_str());
    }
    return 0;
}
