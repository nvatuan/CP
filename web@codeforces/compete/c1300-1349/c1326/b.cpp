#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a (n, 0);
	vector<int> b (n);
	for (int &i : b) cin >> i;
	// --
	a[0] = b[0];
	int x = 0;
	for(int i = 1; i < n; i++) {
		x = max(x, a[i-1]);
		a[i] = b[i] + x;
	}
	for(int &i : a) cout << i << " ";
	cout << endl;
}

int main() {
	solve();
}
