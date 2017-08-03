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

void print_space(int);
int find(char);

using namespace std;

int main()
{
	//freopen("output.txt","w",stdout);
	char name[50];
	char prin[50];
	printf ("         NAME                     SOUNDEX CODE\n");
	while(gets(name))
	{
		int count = 1;
		print_space(9);
		printf("%s",name);
		int len = strlen(name);
		print_space(25 - len);
		int kye = find(name[0]);
		printf("%c",name[0]);
		prin[1] = '0';
		prin[2] = '0';
		prin[3] = '0';
		for(int i = 1 ; i < len ;i++)
		{
			int l = find(name[i]);
			if(l != 0 && l != kye) prin[count++] = l + 48;
			if(l != kye) kye = l;
		}
		printf("%c%c%c\n",prin[1],prin[2],prin[3]);
	}
	printf ("                   END OF OUTPUT\n");
 	return 0;
}
void print_space(int n)
{
	for(int i = 0 ; i < n ; i++)
	printf(" ");
}
int find(char ch)
{
	if( ch == 'A' ||ch == 'E' ||ch == 'I' ||ch == 'O' ||ch == 'U' ||ch == 'Y' ||ch == 'W' || ch == 'H') return 0;
	else if(ch == 'C' ||ch == 'S' ||ch == 'K' ||ch == 'G' ||ch == 'J' ||ch == 'Q' ||ch == 'X' || ch == 'Z') return 2;
	else if(ch == 'B' ||ch == 'P' ||ch == 'F' ||ch == 'V') return 1;
	else if(ch == 'D' || ch == 'T') return 3;
	else if(ch == 'M' || ch == 'N') return 5;
	else if(ch == 'L') return 4;
	else if(ch == 'R') return 6;       
}
