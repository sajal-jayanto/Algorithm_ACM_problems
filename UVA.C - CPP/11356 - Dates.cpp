#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
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
map < string, int > mymap;
int year, month, day;
void upgteat();
bool leapyear();


int main()
{
	mymap["January"] = 1; mymap["February"] = 2; mymap["March"] = 3;
	mymap["April"] = 4; mymap["May"] = 5; mymap["June"] = 6;
	mymap["July"] = 7; mymap["August"] = 8; mymap["September"] = 9;
	mymap["October"] = 10; mymap["November"] = 11; mymap["December"] = 12;
	char temp[5][50];
	char *p;
	int t,cnt,cc = 0;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		scanf("%s", temp[0]);
		scanf("%d",&cnt);
		int k = 1;
		p = strtok(temp[0] , "-");
		while(p != NULL)
        {
            strcpy(temp[k++] , p);
            p = strtok(NULL , "-");
        }
        year = atoi(temp[1]);
        month = mymap[temp[2]];
        day = atoi(temp[3]);
        while(cnt--) upgteat();

        printf("Case %d: %d-",++cc,year);
        for( map < string , int >::iterator it = mymap.begin() ; it != mymap.end() ; it++)
        {
            if(it->second == month)
            {
                printf("%s-%02d\n",it->first.c_str() , day);
                break;
            }
        }
	}
	return 0;
}

void upgteat()
{
    if(day == 28 || day == 29 || day == 30 || day == 31)
    {
        if(day == 28)
        {
            if(month == 2)
            {
                if(leapyear()) day++;
                else
                {
                    day = 1;
                    if(month == 12)
                    {
                        month = 1;
                        year++;
                    }
                    else month++;
                }
            }
            else day++;
        }
        else if(day == 29)
        {
            if(month == 2)
            {
                if(leapyear())
                {
                    day = 1;
                    if(month == 12)
                    {
                        month = 1;
                        year++;
                    }
                    else month++;
                }
            }
            else day++;
        }
        else if(day == 30)
        {
            if(month == 4 || month == 6 || month == 9 || month == 11)
            {
                day = 1;
                if(month == 12)
                {
                    month = 1;
                    year++;
                }
                else month++;
            }
            else day++;
        }
        else
        {
            day = 1;
            if(month == 12)
            {
                month = 1;
                year++;
            }
            else month++;
        }
    }
    else day++;
}

bool leapyear()
{
    if((year % 4 == 0) &&!(year % 100 == 0)|| (year % 400 == 0)) return true;
    return false;
}
