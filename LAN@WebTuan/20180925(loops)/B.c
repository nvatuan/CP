#include <stdio.h>

int main(){
	int s, i, n;
	scanf("%d", &n);

	s = 1;
	for(i = 1; i < n; i++){printf(" ");}
	printf("*");
	for(i = 1; i < n; i++){printf(" ");}
		//in n-1 " "
	printf("\n");
	s++;
	//
	while(s < n){
		for(i = 1; i <= (n-s); i++){printf(" ");}
		printf("*");
		for(i = 1; i <= (s-1)*2 - 1; i++){printf(" ");}
		printf("*");
		for(i = 1; i <= (n-s); i++){printf(" ");}
		s++;
		printf("\n");
	}
	if(s == n) for(i = 1; i <= (n*2-1); i++){printf("*");}
}