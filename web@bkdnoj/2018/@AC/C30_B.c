#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

long long min(long long a, long long b){
	return (a < b) ? a : b;
}

int main(){
	int n, k, i;
	long x[100000]; 
	long long answer = LLONG_MAX, dsum[100000];

	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", &x[i]);

	if(n == 1) printf("%ld", abs(x[0]));
	else{
		dsum[0] = 0;
		for(i = 1; i < n; i++) dsum[i] = dsum[i-1] + abs(x[i] - x[i-1]);
		
		for(i = 0; i <= n-k; i++){
			answer = min( min(abs(x[i]), abs(x[i+k-1])) + dsum[i+k-1]-dsum[i] , answer);
		}
		printf("%lld", answer);
	}
}