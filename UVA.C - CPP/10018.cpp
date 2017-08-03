#include<stdio.h>
int palindrome(long long);
int main()
{
	long long t,n,number,revers,count;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&number);
		count=0;
		while(1)
		{
			n=number;
			revers=0;
			while(n!=0)
			{
    			revers=revers*10;
    			revers=revers+n%10;
    			n=n/10;
    	    }
    	    count++;
    	    number=number+revers;
    	    if(palindrome(number)==1)
			{
    	    	printf("%lld %lld\n",count,number);
    	    		break;
    	    }
    	    
		}	
	}
	return 0;	
}
int palindrome(long long num)
{
	long long n,revers=0;
	n=num;
	while(n!=0)
	{
    	revers=revers*10;
    	revers=revers+n%10;
    	n=n/10;
	}
	if(num==revers)return 1;
	else return 0;
}
