#include<stdio.h>
int main()
{
    int t,n,k,i,B,W,T,A;
    char a[20];
    scanf("%d",&t);
    if(t<101)
    for(k=1;k<=t;k++)
    {
        B=W=T=A=0;
        scanf("%d ",&n);
        if(n>0 && n<11)
        {
            scanf("%s",a);
        for(i=0;i<n;i++)
        {
            if(a[i]=='B')
            {
                B++;
            }
            else if(a[i]=='W')
            {
                W++;
            }
            else if(a[i]=='T')
            {
                T++;
            }
            else if(a[i]=='A')
            {
                A++;
            }
        }
        if(A==n)
        {
            printf("Case %d: ABANDONED\n",k);
        }
        else if(B>0 && W==0 && T==0)
        {
            printf("Case %d: BANGLAWASH\n",k);
        }
        else if(W>0 && B==0 && T==0)
        {
            printf("Case %d: WHITEWASH\n",k);
        }
        else if(B==W)
        {
            printf("Case %d: DRAW %d %d\n",k,B,T);
        }
        else if(W>B)
        {
            printf("Case %d: WWW %d - %d\n",k,W,B);
        }
        else if(B>W)
        {
            printf("Case %d: BANGLADESH %d - %d\n",k,B,W);
        }
        }
    }
    return 0;
}
