// http://bkdnoj.dut.udn.vn/public/practice_problem.php?id=Math2_5
#include <bits/stdc++.h>
using namespace std;

int minPrime[1000001];

void sieveMinPrime(){
	minPrime[0] = minPrime[1] = 1;
	for( long long i = 2; i <= 1000000; i++ )
		if( !minPrime[i] ){
			minPrime[i] = i;
			for( long long j = i*i; j <= 1000000; j += i )
				if(!minPrime[j]) minPrime[j] = i;
		}
}

int divisors(int n){
	int factor = minPrime[n];
	int fcount = 1;
	int dcount = 1;
	//
	while( n > 1 ){
		if( minPrime[n] == factor ) {
			fcount++;
		} else {
			dcount *= (fcount);
			factor = minPrime[n];
			fcount = 2;
		}
		n /= minPrime[n];
	}
	dcount *= (fcount);
	return dcount;
}

int ans[1000001];

int main(){
	sieveMinPrime();
	//
	ans[0] = 0; ans[1] = 1;
	for(int i = 2; i <= 1000000; i++){
		ans[i] = max(ans[i-1] + 1, divisors(i)*i);
	}
	//
	long long n, T;
	for(cin >> T; T; T--){
		cin >> n;
		cout << ans[n] << '\n';
	}
}
