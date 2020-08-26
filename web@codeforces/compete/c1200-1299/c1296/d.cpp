#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> h (n, 0);
	for(int &i : h) cin >> i;
	// --
	for(int &hp : h) {
		hp %= (a+b);
		if(!hp) hp = (a+b);
		// cout << hp << " ";
	}
	sort(h.begin(), h.end());
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(h[i] <= a) {
			ans++;
			continue;
		}
		int K = (h[i] - a)/a + !!((h[i] - a)%a);
		if(k - K >= 0) {
			k -= K;
			ans++;
		}
	}
	cout << ans;
}
