#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a (n);
	for (int &i : a) cin >> i;
	// --
	long long ans1 = (1LL*(n)*(n+1)	- 1LL*(n-k)*(n-k+1))/2;
	const long long M = 998244353;
	long long ans2 = 1;
	
	unordered_map<int, int> Chose;
	for (int i = n-k+1; i <= n; i++) Chose[i] = 1;

	int st = 0, en = n-1;
	while (Chose[a[st]] == 0) st++;
	while (Chose[a[en]] == 0) en--;
	for (int prv = st, i = st+1; i <= en; i++) {
		if ( Chose[a[i]] ) {
			ans2 *= (i - prv);
			ans2 %= M;
			prv = i;
		}
	}
	cout << ans1 << " " << ans2 << endl;
}

int main() {
	solve();
}
