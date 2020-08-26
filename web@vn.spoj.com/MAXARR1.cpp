#include <bits/stdc++.h>
using namespace std;

long long ans[100001];
long long A[100001];

int main() {
	A[0] = 0; A[1] = 1;
	ans[1]	=	1;
	for(int i = 2; i < 100001; i++) {
		if(i & 1) 	A[i] = A[i/2] + A[i/2 + 1];
		else		A[i] = A[i/2];
		ans[i] = max(ans[i-1], A[i]);
	}
	int t, n;
	for(scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
}