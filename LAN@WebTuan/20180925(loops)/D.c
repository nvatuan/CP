#include <stdio.h>

int main(){
	long n;
	scanf("%ld", &n);

	long b = 1;
	int bi = 0;

	if(n == 0) printf("0");
	else
	{
		while(b*2 <= n){
			bi++;
			b *= 2;
		}

		while(n>0){
			n -= b;
			printf("1");
			b /= 2;
			while(b > n){
				b /= 2;
				bi--;
				printf("0");
			}
		}	
	}
}