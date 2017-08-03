#include<cstdio>
#include<cstring>
#include<map>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    map<string,string> mymap;
    string frist,second;
    char input[100];
    char *p;
    while(gets(input))
    {
        if(strlen(input) == 0) break;
        p = strtok(input," ");
        frist = p;
        p = strtok('\0',"");
        second = p;
        mymap[second] = frist;
    }
    while(gets(input))
    {
        frist = input;
        if(mymap[frist].length() == 0)
        {
            printf("eh\n");
        }
        else printf("%s\n",mymap[frist].c_str());
    }
    return 0;
}
