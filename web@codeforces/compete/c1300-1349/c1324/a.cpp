#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a (n);
	//
	int odd = 0;
	for (int &i : a) {
		cin >> i;
		odd += (i % 2 == 1);
	}
	// --
	cout << ( (odd == n or odd == 0) ? "YES\n" : "NO\n" );
}

int main() {
	ios::sync_with_stdio(0);
	int t;
	for (cin >> t; t; t--) solve();
}
