#include <stdio.h>
#include <stdlib.h>

int main(){
	long long n;
	int s = 1;
	scanf("%lld", &n);

	while(n > 0){
		
		if((n % 10 != 4) && (n % 10 != 7)){
			s = 0;
			break;			
		}
		n /= 10;
	}
	if(s) printf("YES");
	else printf("NO");
}