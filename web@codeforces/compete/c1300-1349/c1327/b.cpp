#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> daugh (n, 0);
	vector<int> princ (n, 0);
	int Coup = 0;
	for (int i = 0; i < n; i++) {
		int Min = INT_MAX;
		int C, p;
		for (cin >> C; C; C--) {
			cin >> p;
			p--;
			if (!princ[p]) Min = min(Min, p);
		}
		if (Min != INT_MAX) {
			daugh[i] = 1;
			princ[Min] = 1; 
			Coup++;
		}
	}
	if (Coup < n) {
		cout << "IMPROVE\n";
		for (int i = 0; i < n; i++) 
			if (!daugh[i]) {
				cout << i+1 << " ";
				break;
			}
		for (int i = 0; i < n; i++)
			if (!princ[i]) {
				cout << i+1 << endl;
				break;
			}
	} else {
		cout << "OPTIMAL\n";
	}
}

int main() {
	int t;
	for (cin >> t; t; t--) solve();
}
