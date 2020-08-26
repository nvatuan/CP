#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> dp;
int maxdp[256];

int main() {
	cin >> N;
	dp.resize(N, 1);
	string S;
	cin >> S;
	// --
	for(int i = 0; i < N; i++) {
		for(int c = 'a'; c <= 'z'; c++) {
			if(c > S[i]) {
				dp[i] = max(maxdp[S[i]], maxdp[c] + 1);
			}
		}
		maxdp[S[i]] = max(dp[i], maxdp[S[i]]);
	}
	//
	cout << *max_element(dp.begin(), dp.end()) << endl;
	for(int i = 0; i < N; i++) {
		cout << dp[i] << " ";
	}
}
