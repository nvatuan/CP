#include <bits/stdc++.h>
using namespace std;

long long t, n, m, k;
long long sC, sA, eC, eA;

int main(){
	cin >> n >> m >> t;
	while(t--){
		cin >> sC >> sA >> eC >> eA;
		//--
		long long G = __gcd(n, m);
		if(sC == 1){
			sA = (sA / (n/G) ) + !!( sA % (n/G) );
		}
		if(sC == 2){
			sA = (sA / (m/G) ) + !!( sA % (m/G) );
		}
		if(eC == 1){
			eA = (eA / (n/G) ) + !!( eA % (n/G) );
		}
		if(eC == 2){
			eA = (eA / (m/G) ) + !!( eA % (m/G) );
		}
		//--
		cout << (sA == eA ? "YES\n" : "NO\n");
	}
}
