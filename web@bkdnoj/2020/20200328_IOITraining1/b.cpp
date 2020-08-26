#include <bits/stdc++.h>
using namespace std;

int Next() {
	int x; cin >> x;
	return x;
}
// --

void solve() {
	int n = Next();
	vector< int > a (n);
	generate( a.begin(), a.end(), Next );
	//
	sort(a.begin(), a.end());
	long long minProfit = 0;
	for ( int k = n-1, i = 0; k >= 0; k--) {
		if (i != 2) minProfit += a[k];
		i = (i + 1) % 3;
	}
	cout << minProfit << endl;
}

//


int main() {
	for (int t = 1; t; t--) solve();
}
