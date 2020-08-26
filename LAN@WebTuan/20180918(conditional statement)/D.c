#include <stdio.h>

int main(){
	double a, b, c, d;
	scanf("%lf%lf%lf", &a, &b, &c);
	d = 0.2*(a + b) + 0.6*c;

	if((0.0 <= d)&&(d <  4.0)) printf("F");
	if((4.0 <= d)&&(d <  5.5)) printf("D");
	if((5.5 <= d)&&(d <  7.0)) printf("C");
	if((7.0 <= d)&&(d <  8.5)) printf("B");
	if((8.5 <= d)&&(d <=10.0)) printf("A");
}