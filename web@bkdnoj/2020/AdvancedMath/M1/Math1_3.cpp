// http://bkdnoj.dut.udn.vn/public/practice_problem.php?id=Math1_3
#include <bits/stdc++.h>
using namespace std;

const int M = int(1e9) + 7;
long long T, n;

long long present(long long n){
	if( n == 1 ) return 1;
	if( n == 2 ) return 6;
	if( n % 2 ){
		return ( ((n-1)*6 - (n-2)) % M + (4*(n-1)/2 % M)*((n-2) %M) ) % M;
	} else {
		return ( ((n-1)*6 - (n-2)) % M + (4*(n-2)/2 % M)*((n-1) %M) ) % M;
	}
}

int main(){
	for(cin >> T; T; T--){
		cin >> n;
		printf("%lld\n", present(n));
	}
}
