#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	//
	int n;
	string S;
	cin >> n;
	cin >> S;
	//
	vector<int> A (n+1, 0);
	for (int i = 0; i < n; i++) {
		A[i+1] = (S[i] == ')' ? -1 : 1);
		A[i+1] += A[i];
	}
	if (A[n] != 0) {
		cout << "-1\n";
	} else {
		int ans = 0;
		int idx = 0;
		bool negFlag = false;
		//
		for (int i = 0; i <= n; i++) {
			if (A[i] < 0) {
				if (!negFlag) idx = i;
				negFlag = true;
			}
			if (negFlag && (A[i] == 0)) {
				ans += (i - idx + 1);
				negFlag = false;
			}
		}
		//
		cout << ans << '\n';
	}
}
