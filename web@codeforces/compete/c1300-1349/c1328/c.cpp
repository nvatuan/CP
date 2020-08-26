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
	string x;
	x = In(x);
	//
	string a, b;
	bool minmaxdeterm = false;
	pair<char, char> if_x[] = {
		{'0', '0'}, {'0', '1'}, {'1', '1'}
	};
	for (int i = 0; i < x.length(); i++) {
		a += if_x[ int(x[i] - '0') ].first;
		b += if_x[ int(x[i] - '0') ].second;
		if(!minmaxdeterm & (x[i] == '1')) {
			swap(if_x[1].first, if_x[1].second);
			if_x[2] = make_pair('2', '0');
			minmaxdeterm = true;
		}
	}
	Out(a, '\n');
	Out(b, '\n');
}
// ---------------------------------


int main() {
	for (int t = In(t); t; t--) solve();
}
