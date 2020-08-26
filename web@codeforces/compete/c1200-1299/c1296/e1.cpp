#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; string s;
	cin >> n;
	cin >> s;
	// --
	vector<bool> col (n, 0);
	vector<bool> lock(n, 0);
	for(int i = 0; i < n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(s[j] > s[i]) {
				if(lock[i] == 0) {
					lock[i] = 1;
					col[i]  = !col[j];
					continue;
				}
				if(col[i] == col[j] and lock[i] == 1) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	for(bool b : col) cout << b;
}

