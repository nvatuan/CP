#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S;
	cin >> S;
	S = 'R' + S + 'R';
	// --
	int ans = 0;
	int prvidx = 0;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] == 'R') {
			ans = max(ans, i - prvidx);
			prvidx = i;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	int t;
	for (cin >> t; t; t--) solve();
}
