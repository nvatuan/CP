#include<stdio.h>
int main(){
	int h,m,s,n;
	//printf ("nhap vao thoi gian bay gio va so giay tiep theo :");
	scanf ("%d%d%d%d",&h,&m,&s,&n);
		h=(((h+((m+((s+n)/60))/60))-1)%12+1);
		m=(m+((s+n)/60))%60;
		s=(s+n)%60;
	printf("%d %d %d" ,h ,m ,s);
	}