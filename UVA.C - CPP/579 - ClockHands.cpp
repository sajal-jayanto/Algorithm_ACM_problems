#include<cmath>
#include<cstdio>

using namespace std;

float H, M;

int main() {
	for(;;) {
		scanf("%f:%f", &H, &M);
		if(H == 0 && M == 0) break;

		if(H == 12) H = 0;
		float hangle = 30.0 * H + (M / 60) * 30.0;
		float mangle = M * 6.0;
		printf("%.3f\n", abs(hangle - mangle) > 180? \
			360.0 - abs(hangle - mangle) : abs(hangle - mangle));
	}
}
