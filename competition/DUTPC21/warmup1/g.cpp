#include <bits/stdc++.h>
using namespace std;

void generate_lucky(int len, int &ans, int &n) {
	// lucky with 1 type of digit
	long long mult = stoll(string(len, '1'));
	for (int d=1; d<10; d++) {
		if (mult*d <= n) ans++;
	}

	// lucky with 2 type of digit
	if (len == 1) return;
	for (long long i=(1LL<<(len-1)); i<(1LL<<len)-1; i++) {
		for (int d1=1; d1<10; d1++)
		for (int d2=0; d2<10; d2++) 
			if (d1!=d2) {
				long long num=0;
				for (long long b=len-1; b>=0; b--) {
					num *= 10;
					if (i&(1LL<<b)) num += d1;
					else num += d2;
				}
				ans += (num <= n);
			}
	}
}

int main() {
	int n;
	cin >> n;
	
	int ans=0;
	for (int len=1; len<=10; len++) generate_lucky(len, ans, n);
	cout << ans << endl;
}
