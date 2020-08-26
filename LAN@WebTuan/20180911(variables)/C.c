#include <stdio.h>
 
int main(){
	int h,m,s,x;
	scanf("%d%d%d%d", &h, &m, &s, &x);

	s = s + x;
	m = m + s / 60;
	//them phut
	s = s % 60;

	h--;
	// bien kim gio tu 1-12 thanh 0-11
	h = h + m / 60;
	m = m % 60;

	h = h % 12;
	h++;
	// tang kim gio len de dung voi dinh dang theo de bai
	printf("%d%c%d%c%d", h,32,m,32,s);
}
