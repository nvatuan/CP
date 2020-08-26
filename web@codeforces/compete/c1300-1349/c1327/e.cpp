#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<long long> tenPow (n + 1, 1);	
	vector<long long> bsum (n, 0);
	for (int i = 1; i <= n; i++)
		tenPow[i] = (tenPow[i-1]*10) % M;
	for (int i = 1; i <= n; i++) {
		bsum[n-i] = (i * tenPow[i]) % M;
	}

	vector<long long> ans (n, 0);
	ans[n-1] = 10;
	long long prefix = 0;
	long long minus = 0;
	//
	for (int i = 2; i <= n; i++) {
		prefix = (prefix + ans[n-i+1]) % M;
		minus = (minus + ans[n-i+1]) % M;
		minus = (minus + prefix) % M;
		//cout << i << " " << minus << endl;
		//
		ans[n-i] = (bsum[n-i] - minus + M) % M;
	}
	for (long long &i : ans) cout << i << " ";
}

int main() {
	solve();
}

