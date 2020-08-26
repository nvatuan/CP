#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[200001];

int dp[200001];

#define V first
#define I second

int team[200001];

int main() {

	fill(dp, dp + 200000, INT_MAX);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	// --
	int team = 2;
	dp[0] = 0;
	dp[1] = a[1].V - a[0].V;
	dp[2] = a[2].V - a[0].V;
	dp[3] = a[3].V - a[0].V;
	dp[4] = a[4].V - a[0].V;
	team[0] = team[1] = team[2] = team[3] = team[4] = 1;
	//
	for(int i = 0; i < n; i++) {
		for(int k = 2; k < 5; k++) {
			dp[i] = min(dp[i], dp[i-1] +
		}
	}
	
}
