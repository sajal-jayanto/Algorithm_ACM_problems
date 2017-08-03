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

#define MAX 1005

using namespace std;

char word[MAX];
int DP[MAX][MAX];

int Longest_Palindrome(int,int);

int main()
{
    int t,len;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(DP,-1,sizeof(DP));
        gets(word);
        len = strlen(word) - 1;
        printf("%d\n", Longest_Palindrome(0,len));
    }
    return 0;
}

int Longest_Palindrome(int i , int l)
{
    if(i == l) return 1;
    if(i + 1 == l )
    {
        if(word[i] == word[l]) return 2;
        return 1;
    }
    if(DP[i][l] != -1) return DP[i][l];
    if(word[i] == word[l]) return DP[i][l] = Longest_Palindrome(i + 1,l - 1) + 2;
    else return DP[i][l] = max(Longest_Palindrome(i,l - 1),Longest_Palindrome(i + 1 , l));
}
