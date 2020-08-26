#include <bits/stdc++.h>
using namespace std;

int m, n, k;

int f(int u) {
	return u;
}
int d(int u) {
	return u + m;
}

int main() {
	cin >> m >> n >> k;
	if( k == 0 ) cout << m*n;
	if( k == 1 ) cout << m*n-1;

	//
	vector<vector<int>> EdgeList(m + n, vector<int>());
	vector<vector<int>> rEdgeList(m + n, vector<int>());
	//
	vector<int> inDeg(m + n, 0);
	vector<int> outDeg(m + n, 0);
	//
	for(int a, b, i = 0; i < k; i++) {
		cin >> a >> b;
		a--;
		b--;
		EdgeList[f(a)].push_back(d(b));
		outDeg[f(a)]++;
		//
		rEdgeList[d(b)].push_back(f(a));
		inDeg[d(b)]++;
	}
	//
	unordered_set<int> All;
	for(int i =0; i < m + n; i++) {
		All.insert(i);
	}
	// -- need data struct
	int change = 0;
	do {	
		int in = -1;
		for(int i = 0; i < m+n; i++) {
			if( in == -1 && inDeg[i] > 0 || inDeg[i] > inDeg[in] ) in = i;
		}
		int out = -1;
		for(int o = 0; o < m+n; o++) {
			if( out == -1 && outDeg[o] > 0 || outDeg[o] > outDeg[out] ) out = o;
		}
		if(in == -1 || out == -1) break;
		if( inDeg[in] > outDeg[out] ) {
			for(auto &v : rEdgeList[in]) {
				outDeg[v]--;
			}
			inDeg[in] = 0;
			All.erase(in);
			change = 0;
		} else {
			for(auto &v : EdgeList[out]) {
				inDeg[v]--;
			}
			outDeg[out] = 0;
			All.erase(out);
			change = 0;
		}
	} while( change );
	cout << All.size();
}