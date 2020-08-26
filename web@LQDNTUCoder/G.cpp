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
    if(n < k) return 0;
    if(k == 0 || n == k) return 1;
    return ( f[n] % M * ( mulInverse(f[k], M) % M ) * (mulInverse( f[n-k], M )) ) % M;
}

int main(){
	f[0] = 1;
	for(int i = 1; i <= 100000; i++) f[i] = f[i-1] * i % M;
	long long n, T;
	for(cin >> T; T; T--){
		cin >> n;
		for(long long k = 0; k < n; k++) printf("%lld ", C(k, n));
		printf("%lld", C(n, n));
		if(T) printf("\n");
	}
}
