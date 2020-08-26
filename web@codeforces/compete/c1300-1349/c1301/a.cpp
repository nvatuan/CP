#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a, b, c;
	cin >> a >> b >> c;
	// --
	bool logic = 1;
	int n = a.length();
	for(int i = 0; i < n; i++) {
		logic &= ((a[i] == c[i]) || (b[i] == c[i]));
	}
	cout << (logic ? "YES\n" : "NO\n");
}

int main() {
	int t;
	for(cin >> t; t; t--) {
		solve();
	}
}
