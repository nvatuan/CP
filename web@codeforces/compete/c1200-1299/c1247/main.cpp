
#include <bits/stdc++.h>
using namespace std;
 
int setbit(int a){
	if(a <= 0) assert(0);
	return __builtin_popcountll(a);
}
 
long long n, p, K;
 
int main() {	
	cin >> n >> p;
 
	K = 1;
	while(1) {
		if( n - p*K <= 0 ) {
			cout << -1;
			return 0;
		}
		
		if( setbit(n - p*K) <= K ) {
			cout << K;
			return 0;
		}
		K++;
	}
}