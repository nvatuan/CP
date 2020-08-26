#include <bits/stdc++.h>
using namespace std;

int next() {
	int x; cin >> x;
	return x;
}
// --

void solve() {
	int n = next(), k = next();
	vector< pair<int, int> > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = n - i;
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>());
	vector<int> ans;
	for_each(a.begin(), a.begin()+k, [&](pair<int, int> x){ ans.push_back(n - x.second + 1);});
	sort(ans.begin(), ans.end());
	for (int &i : ans) cout << i << " ";
	cout << endl;
}

//


int main() {
	for (int t = 1; t; t--) solve();
}
