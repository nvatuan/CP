#include <stdio.h>

void redirect(int *px, int *py){
	if(*px == 1) {*px = 0;  *py = 1;  return;}
	if(*py == 1) {*px = -1; *py = 0;  return;}
	if(*px == -1){*px = 0;  *py = -1; return;}
	if(*py == -1){*px = 1;  *py = 0;  return;}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, n;

	int x = 0, y = -1;
	int h = 1, v = 0;

	scanf("%d", &n);
		int repe = 1;
		int thre = n;
		int shortn = n;

	int a[50][50];
	for(i = 0; i < n*n; i++){
		x += v;
		y += h;
		a[x][y] = i;
		
		if(i+1 == thre){
			redirect(&h, &v);
			
			if(repe == 1){
				repe = 2;
				shortn--;
				thre += shortn;
			}
			else{
				repe--;
				thre += shortn;
			}
		}
	}

	for(x = 0; x < n; x++){
		for(v = 0; v < n; v++)
			printf("%d ", a[x][v]);
		printf("\n");
	}
}