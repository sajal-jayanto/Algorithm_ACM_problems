#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int main()
{

    double x1,x2,x3,y1,y2,y3;
    double a,b,c,s,r,area;
    double PI = 2 * acos(0.0);
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF )
    {
        a = pow((x1 - x2),2) + pow((y1 - y2),2);
        a = sqrt(a);
        b = pow((x1 - x3),2) + pow((y1 - y3),2);
        b = sqrt(b);
        c = pow((x2 - x3),2) + pow((y2 - y3),2);
        c = sqrt(c);
        s = (a + b + c) / 2;
        s = s * (s - a) * (s - b) * (s - c);
        s = sqrt(s) * 4;
        r = (a * b * c) / s;
        area = 2 * PI * r;
        printf("%.2lf\n",area);
    }
    return 0;
}
