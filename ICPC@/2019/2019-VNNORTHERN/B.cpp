#include <bits/stdc++.h>
using namespace std;

void gen_substr(string S, unordered_set<string>& SET) {
	for(int i = 0; i < S.length(); i++) {
		string sst = "";
		for(int j = i; j < S.length(); j++) {
			sst += S[j];
			SET.insert(sst);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//
	unordered_set<string> SET;
	string A, B;
	cin >> A >> B;
	gen_substr(A, SET);
	gen_substr(B, SET);
	// --
	for(int L = 1; L < 11; L++) {
		string S (L, '0');
		for(unsigned long long ULL = 0; ULL < (1 << L); ULL++) {
			for(int s = L-1; s >= 0; s--) {
				S[L - s - 1] = ((ULL >> s) & 1 ? '1' : '0');
			}
			if( SET.find(S) == SET.end() ) {
				cout << S << endl;
				return 0;
			}
		}
	}
	//--
	assert(0);
}
