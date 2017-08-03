#include <stdio.h>
int main()
{
	int n;
    double t,a,b,d,e;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&t);
		a = (t * 0.6);
		b = (t * 0.2);
		d = (3.141592654 * b * b );
		e = ((t * a) - d);
		printf("%.2lf %.2lf\n",d,e); 
	}
    return 0;
}
