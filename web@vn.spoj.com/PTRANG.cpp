#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, L;
	cin >> n >> L;
	vector<int> S (n+1, 0), DP(n+1, INT_MAX);
	//
	for (int s, i = 1; i <= n; i++) {
		cin >> s;
		S[i] = S[i-1] + s;
	}
	//
	DP[0] = 0;
	for (int i = 1; i <= n; i++) 
		for(int j = i-1; j >= 0; j--) 
			if( S[i] - S[j] <= L )
				DP[i] = min(DP[i], max(DP[j],L - S[i] + S[j]));
//	for (int &i : DP) cout << i << " ";
	cout << DP[n] << '\n';
}
