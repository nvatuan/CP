#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a (n);
	for (int &i : a) cin >> i;
	// --
	for (int i = 0; i < n; i++) {
		for (int j = i+2; j < n; j++) {
			if (a[i] == a[j]) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	int t;
	for (cin >> t; t; t--) solve();
}
