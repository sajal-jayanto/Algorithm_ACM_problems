#include<stdio.h>
#include<math.h>
int main()
{
    int pad = 24*60;
    int h1;
    int h2;
    int m1;
    int m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    while (h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0)
    {
        int current_time = h1*60+m1;
        int alarm_time = h2*60+m2;
        if (h2 < h1 || (h2 == h1 && m2 < m1))
    	{
            h2 += 24;
        }
    	if (m2 < m1)
        {
            m2 += 60;
            h2--;
        }
        int d_m = m2 - m1;
        int d_h = h2 - h1;
        int d_t = d_h*60+d_m;
        if (d_t < 0)
        {
         	d_t += pad;
        }
        printf("%d\n",d_t);
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    }
    return 0;
}
