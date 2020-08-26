#include <bits/stdc++.h>
using namespace std;

long long Good(long long d, long long gb, long long g, long long b) {
	return (d / gb) * g + min(d % gb, g);
}

void solve() {
	long long n, g, b;
	//
	cin >> n >> g >> b;
	long long L = n, R = 1000000000000000000LL;
	//
	long long gb = g+b;
	while( L < R ) {
		long long mid = (L + R) / 2;
		if( Good(mid, gb, g ,b) < (n+1)/2 )  {
			L = mid + 1;
		} else {
			R = mid;
		}
	}
	cout << L << endl;
}

int main() {
	int t;
	for(cin >> t; t; t--) {
		solve();
	}
}
