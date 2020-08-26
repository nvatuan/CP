#include <stdio.h>

int main(){
	long long n, m, k, c = 1;
	scanf("%lld%lld%lld", &m, &n, &k);

	while(n > 1){
		if(n % 2 == 0) m = m * m % k;
		else {
			c = c * m % k;
			m = m * m % k;
		}
		n = n/2;
	}
	printf("%lld", m * c % k);
}