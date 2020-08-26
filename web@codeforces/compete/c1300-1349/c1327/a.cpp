#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, k;
	cin >> n >> k;
	if ( ((n%2 == k%2) and (k*k <= n)) ) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int t;
	for (cin >> t; t; t--) solve();
}

