#include <bits/stdc++.h>
using namespace std;

int Next() {
	int x; cin >> x;
	return x;
}
// --

int n;

int minKey (vector<long long>& key, unordered_map<int, int> &mstSet) {
	int m = INT_MAX, min_index;
	for (int v = 0; v <= n; v++)
		if (!mstSet[v] && key[v] < m)
			m = key[v], min_index = v;
	return min_index;
}

void solve() {
	n = Next();
	// cost[i][j] = i --> j costs ...
	vector< vector<long long> > cost (n + 1, vector<long long> (n + 1, 0));
	for (int i = 1; i <= n; i++) cin >> cost[0][i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> cost[i][j];
	// --
	vector<long long> parent (n + 1), key (n + 1, INT_MAX);
	unordered_map<int, int> mstSet;

	key[0] = 0;
	parent[0] = -1;

	for (int c = 0; c < n; c++) {
		int u = minKey(key, mstSet);
		mstSet[u] = 1;
		for (int v = 0; v <= n; v++) {
			if (!!cost[u][v] and !mstSet[v] and cost[u][v] < key[v])
				parent[v] = u, key[v] = cost[u][v];
		}
	}

	long long res = 0;
	for (int i = 0; i <= n; i++) {
		//cout << i << " - " << parent[i] << endl;
		res += (parent[i] == -1 ? 0 : cost[parent[i]][i]);
	}
	cout << res << endl;
}

//


int main() {
	for (int t = 1; t; t--) solve();
}
