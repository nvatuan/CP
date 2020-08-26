#include <bits/stdc++.h>
using namespace std;

int T;

void solve() {
	int n;
	vector<int> a;
	cin >> n;
	a.resize(n);
	for(int &i : a) cin >> i;
	// --
	int z = 0;
	for(int &i : a) {
		if(!i) z++, i++;
	}
	int sum = 0;
	for(int &i : a) sum += i;
	if(sum == 0) {
		cout << z + 1 << endl;
	} else {
		cout << z << endl;
	}
}

int main() {
	for(cin >> T; T; T--) {
		solve();
	}
}
