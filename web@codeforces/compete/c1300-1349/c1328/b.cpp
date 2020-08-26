#include <bits/stdc++.h>
using namespace std;

template<typename T>
T In(T x) {
	cin >> x;
	return x;
}

template<typename T, typename U>
void Out(T x, U punc = " ") {
	cout << x << punc;
}

// ---------------------------------
void solve() {
	int n = In(n);
	int k = In(k);
	//
	string ans = string(n, 'a');
	long long state = 0;
	for (int i = 1; i <= n; i++) {
		state += i;
		if (state < k) continue;
	       	else {
			ans[n - i - 1] = 'b';
			long long second = state - k;
			ans[n - i + second] = 'b';
			Out(ans, '\n');
			return;
		}
	}
}
// ---------------------------------


int main() {
	for (int t = In(t); t; t--) solve();
}
