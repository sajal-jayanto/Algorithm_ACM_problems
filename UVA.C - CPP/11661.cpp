#include<stdio.h>
int main()
{
    int L,i,ans,D,R,b,coun;
    char a[2000005];
    while(scanf("%d",&L)==1 && L!=0)
    {
        D=0,R=0,coun=0,ans=1,b=0;
        scanf("%s",a);
        for(i=0;i<L;i++)
        {
            if(a[i]=='Z')
            {
                ans=0;
                break;
            }
            if(a[i]=='D' && R==1)
            {
                if(b==0)
                b=coun;
                if(coun<b)
                b=coun;
                R=0,D=1,coun=1;
            }
            else if(a[i]=='D')
            {
                coun=1;
                D=1;
            }
            else if(a[i]=='R' && D==1)
            {
                if(b==0)
                b=coun;
                if(coun<b)
                b=coun;
                D=0,R=1,coun=1;
            }
            else if(a[i]=='R')
            {
                coun=1;
                R=1;
            }
            else if(a[i]=='.' && coun!=0)
            {
                coun++;
            }
        }
        if(ans==0)
        {
            printf("%d\n",ans);
        }
        else
        {
            if(b==0)
            {
                printf("%d\n",1073741824);
            }
            else
            printf("%d\n",b);
        }
    }
    return 0;
}

