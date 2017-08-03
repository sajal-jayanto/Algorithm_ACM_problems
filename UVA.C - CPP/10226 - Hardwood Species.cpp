#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    map < string,int > list;
    int t,count;
    string c;
    char name[50];
    scanf("%d",&t);
    gets(name);
    gets(name);
    while(t--)
    {
        count = 0;
        while(gets(name))
        {
            if(strlen(name) == 0) break;
            c = name;
            list[c]++;
            count++;
        }
        map < string ,int > ::iterator i;
        for(i = list.begin(); i != list.end(); i++)
        {
            printf("%s %.4lf\n",(*i).first.data(),(*i).second * 100.00 / count * 1.00);
        }
        if(t > 0) printf("\n");
        list.clear();
    }
}
