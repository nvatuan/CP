#include <stdio.h>

void sort(int *p, int n){

	int *p2, tmp;

	for(int i = 0; i < n-1; i++){
		p2 = p;
		for(int j = i+1; j < n; j++){
			p2++;
			if(*p > *p2){
				tmp = *p;
				*p = *p2;
				*p2 = tmp;
			}
		}
		p++;
	}

}

long min(long a, long b){
	if(a < b) return a;
	else return b;
}

int main () {
   
   int n, a[1000], b[1000], i, j;
   long long eff = 0, seff = 0;

   scanf("%d", &n);
   for( i = 0; i < n; i++ ){
   		scanf("%d", &a[i]);
   }
   for( i = 0; i < n; i++ ){
   		scanf("%d", &b[i]);
   }

   sort(&a[0], n);
   sort(&b[0], n);

   for( i = 0; i < n; i++ ){
   		eff += a[i] * b[n-1 - i];
   }

   for( i = 0; i < n; i++ ){
   		seff += b[i] * a[n-1 - i];
   }

   printf("%lld", (eff < seff)?eff:seff);
}