#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S;
	cin >> S;
	int l = 0, r = (S.length() - 1);
	while(S[l] == '0' and l < S.length()) l++;
	while(S[r] == '0' and r >= 0) r--;
	//
	if(l > r) {
		cout << 0 << endl;
		return;
	} else {
		int ans = 0;
		for(; l != r; l++) 
			ans += (S[l] == '0');
		cout << ans << endl;
	}
}

int main() {
	int t;
	for(cin >> t; t; t--) {
		solve();
	}
}
