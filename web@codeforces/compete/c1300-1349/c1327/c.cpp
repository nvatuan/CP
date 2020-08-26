#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string instruct = "";
	instruct += string(n-1, 'U');
	instruct += string(m-1, 'L');
	//
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			instruct += string((m-1), 'L');
		}
		else {
			instruct += string((m-1), 'R');  
		}
		instruct += 'D';
	}
	cout << instruct.length() << endl;
	cout << instruct << endl;
	assert(instruct.length() <= 2*n*m);
}

int main() {
	solve();
}

