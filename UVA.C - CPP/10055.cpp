#include <stdio.h> 
int main() 
{ 
unsigned long int a, b, c; 
	while (scanf("%lu %lu", &a, &b)== 2) 
		{ 
			c = (a > b)?a-b:b-a; 
			printf("%lu\n", c); 
		} 
return 0; 
}
