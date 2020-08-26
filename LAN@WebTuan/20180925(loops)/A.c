#include <stdio.h>

int main(){
	int n;
	long long g = 1;

	scanf("%d", &n);
	while(n > 1){
		g = g * n;
		n--;
	}
	printf("%lld", g);	
}