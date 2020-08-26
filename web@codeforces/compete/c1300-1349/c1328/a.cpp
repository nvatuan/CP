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
	int a = In(a);
	int b = In(b);
	//
	Out( (b - (a%b)) % b, '\n' );
}
// ---------------------------------


int main() {
	for (int t = In(t); t; t--) solve();
}
