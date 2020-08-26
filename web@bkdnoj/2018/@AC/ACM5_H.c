#include <stdio.h>

int generate(int k, int n, int subnary){
	int i;
	if(n = 0){
		printf(subnary,"\n");
	}
	else{
		for(i = 1; i <= k; i = i + 1 ){
			generate(k, n-1, subnary*10+i);
	}}
	return 0;
}

int main(){
	int k, n;
	scanf("%d", &k);
	scanf("%d", &n);
	generate(k, n, 0);

	return 0;
}