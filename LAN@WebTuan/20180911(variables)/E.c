#include <stdio.h>

int main(){
	int a1, a2, a3, a4, a5;
	scanf("%ld%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	printf("%ld", a1*a2 % 1000007 *a3 % 1000007 *a4 % 1000007 *a5 % 1000007 );
}