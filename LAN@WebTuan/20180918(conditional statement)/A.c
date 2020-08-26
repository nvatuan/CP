#include <stdio.h>

int main(){
	long n;
	scanf("%ld", &n);
	if( (n%400 == 0) || ((n%4 == 0)&&(n%100 != 0)) )
		printf("YES");
	else printf("NO");
}