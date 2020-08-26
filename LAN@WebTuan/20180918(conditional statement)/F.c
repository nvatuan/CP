#include <stdio.h>

int main(){
	long n;
	scanf("%d", &n);
	if(n % 8 != 0) printf("NO");
	else printf("%ld %ld %ld", 11*n/8, 7*n/8, 6*n/8);
}