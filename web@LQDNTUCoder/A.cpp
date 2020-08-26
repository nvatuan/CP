#include <bits/stdc++.h>
using namespace std;

const int M = int(1e9) + 7;

long long f[100001];

long long binExp(long long base, long long e, long long M){
	if(e == 0) return 1;
	if(e == 1) return base % M;
	if(e % 2) return ( binExp(base * base % M, e/2, M) * base % M);
	else return ( binExp(base * base % M, e/2, M) );
}

long long mulInverse(long long k, long long M){
	return binExp(k, M-2, M) % M;
}

long long C(long long k, long long n){
	return ( f[n] % M * ( mulInverse(f[k], M) ) * (mulInverse( f[n-k], M )) ) % M;
}

int main(){
	f[0] = 1;
	for(int i = 1; i <= 100000; i++) f[i] = (f[i-1] * i % M);
	//--
	int n, k;
	
	cin >> n >> k;
	vector<long long> a(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	//
	long long ans = 0;
	for(int j = n; k <= j; j--) ans = (ans + a[j]*C(k-1, j-1)) % M;
	for(int i = 1; i <= n-k+1; i++) {
		ans = (ans - (a[i]*C(k-1, n-i)) + M) % M;
	}
	cout << ans;
}
