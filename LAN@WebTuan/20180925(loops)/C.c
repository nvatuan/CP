#include <stdio.h>

int main(){
	int i, j, digits = 0;
	long n, na, t = 0;
	long long expo;
	scanf("%ld", &n);

	i = n;
	while(i > 0){
		digits++;
		i = i / 10;
	}

	//get leng

	na = n;
	for(i = 1; i <= digits; i++){
		expo = 1;
		printf("n = %d\n", n);

		for(j = 1; j <= digits; j++){
			expo = expo * (n%10);
			printf("	%d => %d\n", j, expo);
		}


		t = t + expo;
		n = n / 10;

		printf("Tong hien tai la: %d\n", t);
	}

	if(na == t) printf("YES");
	else printf("NO");

}