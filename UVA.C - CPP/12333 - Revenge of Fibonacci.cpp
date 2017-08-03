#include<bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

struct Bigint {
    string a;
    int sign;
    Bigint() {}
    Bigint( string b ) { (*this) = b; }
    int size() {
        return a.size();
    }
    Bigint inverseSign() {
        sign *= -1;
        return (*this);
    }
    Bigint normalize( int newSign ) {
        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
            a.erase(a.begin() + i);
        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }
    void operator = ( string b ) {
        a = b[0] == '-' ? b.substr(1) : b;
        reverse( a.begin(), a.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
    }
    bool operator < ( const Bigint &b ) const {
        if( sign != b.sign ) return sign < b.sign;
        if( a.size() != b.a.size() )
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )
            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator == ( const Bigint &b ) const {
        return a == b.a && sign == b.sign;
    }
    Bigint operator + ( Bigint b ) {
        if( sign != b.sign ) return (*this) - b.inverseSign();
        Bigint c;
        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {
            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator - ( Bigint b ) {
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign; sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ ) {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    string to_string() {
        string ret; int cnt = 0;
        for(int i = a.size() - 1 ; i >= 0 ; --i)
        {
            ret = ret + a[i];
            ++cnt;
            if(cnt >= 42) return ret;
        }
        return ret;
    }
};

struct trie {

    int mn ;
    trie *next[10 + 1];
    trie() { for(int i = 0 ; i < 10 ; ++i) next[i] = NULL;  mn = 100010; }

}*root;

void insert(string s , int len , int id)
{
    trie *n = root;
    int l;
    for(int i = 0 ; i < len ; ++i)
    {
        l = s[i] - '0';
        if(n->next[l] == NULL) n->next[l] = new trie();
        n = n->next[l];
        n->mn = min(n->mn , id);
    }
}

int search(char *s , int len)
{
    trie *n = root;
    int l ;
    for(int i = 0 ; i < len ; ++i)
    {
        l = s[i] - '0';
        if(n->next[l] == NULL) return 100010;
        n = n->next[l];
    }
    return n->mn;
}


int main()
{
   // freopen("input.txt" , "r" , stdin);
    root = new trie();
    Bigint a , b , c ;
    insert("1" , 1 , 0);
    string str = "1";
    a = str; b = str;
    int temp ;
    for(int i = 2 ; i < 100000 ; ++i)
    {
        c = a + b;
        insert(c.to_string() , min(c.size() , 42) , i);
        a = b ;
        b = c;
    }
    char s[50];
    int t , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , s);
        temp = search(s , strlen(s));
        if(temp == 100010) pf("Case #%d: -1\n" , ++cc);
        else pf("Case #%d: %d\n" ,  ++cc , temp);
    }
    return 0;
}
