#include <stdio.h>

int main(){
	long a, b, c;
	scanf("%ld%ld%ld", &a, &b, &c);
	if ((a + b > c) && (b + c > a) && (c + a > b)) 
		printf("YES");
	else printf("NO");
}