#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S;
	cin >> S;
	int n = S.length();
	if ( n == 1 ) {
		cout << S << '\n';
		return;
	}
	vector< vector<int> > dp ( n, vector<int> (n, 0));

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int len = 1; len <= n; len++) {
		for (int i = 0; i+len < n; i++) {
			if( S[i] == S[i+len] && ((i+1 == i+len) || (dp[i+1][i+len-1])) )
				dp[i][i+len] = 1;
		}
	}
	// --
	string rS = string(S.rbegin(), S.rend());
	unordered_map<string, int> suffixes;
	//
	{
		string cum = "";
		for (int i = 0; i < n; i++) {
			cum += rS[i];
			suffixes[cum] += 1;
		}
	}
	string ans = "";
	for (int i = 0; i < n; i++) {
		if (dp[0][i])
			if (ans.length() < (i+1))
				ans = string(S.begin(), S.begin()+i+1);
		if (dp[i][n-1])
			if (ans.length() < (n-i))
				ans = string(S.begin() + i, S.end());
	}
	//
	{
		string cum = "";
		for (int i = 0; i < n; i++) {
			cum += S[i];
			if ( suffixes[cum] != 0 ) {
				int st = i + 1;
				int rs = n - st - 1;
				for (int i = st; i <= rs; i++) {
					if ( ans.length() < (cum.length() * 2 + (i-st+1)*dp[st][i]) )
						ans = cum + string(S.begin()+st, S.begin()+i+1) + string(cum.rbegin(), cum.rend());
					if ( ans.length() < (cum.length() * 2 + (rs-i+1)*dp[i][rs]) )
						ans = cum + string(S.begin()+i, S.begin()+rs+1) + string(cum.rbegin(), cum.rend());
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	int t;
	for(cin >> t; t; t--) solve();
}
