#include <bits/stdc++.h>
using namespace std;

int n, h, l, r;

bool in_range(int L, int x, int R) {
	if (L <= R) return (L <= x) and (x <= R);
	else return (L <= x) or (x <= R);
}

void solve() {
	cin >> n >> h >> l >> r;
	vector< vector<int> > dp (n+1, vector<int> (h, 0));
	//
	int minRange = 0, maxRange = 0;
	for (int a, i = 0; i < n; i++) {
		cin >> a;
		//
		for (int H = minRange; H != maxRange; H = (H + 1)%h) {
			for (int offx = -1; offx < 1; offx++) {
				dp[i+1][(H+a+offx)%h] =
			max( dp[i+1][(H+a+offx)%h], dp[i][H] + in_range(l, (H+a+offx)%h, r) );
			}
		}
		//
		// printf("i = %d | minR = %d ; maxR = %d\n", i, minRange, maxRange);
		minRange = (minRange + a - 1) % h;
		maxRange = (maxRange + a) % h;
	}
	//
	// printf("i = END | minR = %d ; maxR = %d\n", minRange, maxRange);
	/*for (auto v : dp) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}*/
	cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	solve();
}
