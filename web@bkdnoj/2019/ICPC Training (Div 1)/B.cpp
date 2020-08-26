#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> V;

void solve() {
	cin >> N >> M;
	V.resize(N);
	for(int& i : V) cin >> i;
	// --
	unordered_set<int> sumPairHash;
	for(int& i : V) {
		for(int& j : V) {
			sumPairHash.insert( i + j );
		}
	}
	//
	for(int& i : V) {
		for(int& j : V) {
			int complement = M - (i + j);
			if(complement < 0) continue; // no need
			if(sumPairHash.find(complement) != sumPairHash.end()) {
				cout << "No\n";
				return;
			}
		}
	}
	//
	cout << "Yes\n";
	return;
}

int T;

int main() {
	for(cin >> T; T; T--) {
		solve();
	}
}
