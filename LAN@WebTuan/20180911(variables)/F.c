#include <stdio.h>

int main(){
	long mmin, d, v, x, trip;
	scanf("%ld%ld%ld", &d, &v, &x);
	
	mmin = ( d+v   - (d-v)  *((2*(d-v)  +1)%2) )/2;
	mmin = ( mmin+x - (mmin-x)*((2*(mmin-x)+1)%2) )/2;

	d -= mmin;
	v -= mmin;
	x -= mmin;

	trip = (d/3 + v/3 + x/3);
	d %= 3;
	v %= 3;
	x %= 3;

	printf("%ld", mmin + trip + (d+v+x)/4 );
}