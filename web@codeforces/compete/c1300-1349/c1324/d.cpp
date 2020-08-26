#include <bits/stdc++.h>
using namespace std;

class topic {
	public:
		int a;
		int b;
		// -- con / decon
		topic() {}
};

void solve() {
	int n;
	cin >> n;
	vector<topic> V (n, topic());
	vector<int> delta (n, 0);
	for (int i = 0; i < n; i++) {
		cin >> V[i].a;
	}
	for (int i = 0; i < n; i++) {
		cin >> V[i].b;
	}

	for (int i = 0; i < n; i++) {
		delta[i] = V[i].b - V[i].a;
	}
	// -- 
	sort( delta.begin(), delta.end() );
	//
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int val = delta[i]*(-1); //V[i].a - V[i].b;
		int idx = lower_bound(delta.begin(), delta.end(), val) - delta.begin();
		//printf("i = %d | idx = %d\n", i, idx);
		ans += (val > 0 ? idx - 1 : idx);
	}
	cout << ans/2 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	solve();
}
