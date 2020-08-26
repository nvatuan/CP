#include <bits/stdc++.h>
using namespace std;

int M(vector<int> &A, int k) {
	int ovraMax = INT_MIN;
	for(int i = 1; i < A.size(); i++) {
		int a1 = (A[i] == -1 ? k : A[i]);
		int a2 = (A[i-1] == -1 ? k : A[i-1]);
		ovraMax = max(ovraMax, abs(a1 - a2));
	}
	return ovraMax;
}

void solve() {
	int n;
	vector<int> a;
	//
	cin >> n;
	a.resize(n, 0);
	for(int &i : a) cin >> i;
	// --
	
	int L = 0, R = 1000000000;
	while(R - L > 3) {
		int m1 = L + (R - L)/3;
		int m2 = R - (R - L)/3;
		if(m1 < L) break;
		if(m2 > R) break;
		//printf("Ternary: L=%d R=%d m1=%d m2=%d\n", L, R, m1, m2);
		// --
		if( M(a, m1) > M(a, m2) ) {
			L = m1;
		} else
		if( M(a, m1) < M(a, m2) ) {
			R = m2;
		} else {
			L = m1;
			R = m2;
		}
	}
	//
	int opt = INT_MAX;
	int ans;
	for(int x = L; x <= R; x++) {
		int v = M(a, x);
		if(opt > v) {
			opt = v;
			ans = x;
		}
	}
	cout << opt << " " << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//
	int t;
	for(cin >> t; t; t--) {
		solve();
	}
}
