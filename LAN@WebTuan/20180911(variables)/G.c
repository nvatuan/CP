#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	a -= (a*b)/(100+b);

	printf("%d", c/a + (c%a + a-1)/a );
}