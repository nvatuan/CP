#include <stdio.h>

int main(){
	long a, b, c, d;
	scanf("%ld%ld%ld%ld", &a, &b, &c, &d);

	if(a < b) a = b;
	if(a < c) a = c;
	if(a < d) a = d;

	printf("%ld", a);
}