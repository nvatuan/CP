// vnoi.info/problems/NKPALIN/
#include <bits/stdc++.h>
using namespace std;

string S;

int main () {
	cin >> S;
	int n = S.length();
	//
	vector< vector<string> > dp (n, vector<string> (n, string("")));
	for (int i = 0; i < n; i++) dp[i][i] += S[i];
	//
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			if (S[i] == S[i+len-1])
				dp[i][i+len-1] = S[i] + dp[i+1][i+len-2] + S[i];
			else
				dp[i][i+len-1] = 
			( dp[i][i+len-2].length() < dp[i+1][i+len-1].length() ? 
				 dp[i+1][i+len-1] : dp[i][i+len-2] );
		}
	}
	//
	cout << dp[0][n-1] << '\n';
}

