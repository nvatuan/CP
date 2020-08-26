#include <stdio.h>

int main(){
	int n;
	int j, i = 2;
	int s = 0;

	scanf("%d", &n);


	while(i <= n){
		if(n % i == 0){
			if(s == 0){ s = 1; }
			else printf(" ");
			
			printf("%d", i);
			while(n % i == 0){n = n / i; }
		}
		i++;
	}
}