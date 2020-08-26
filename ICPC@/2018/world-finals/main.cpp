#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<int> jump;
vector<vector<int>> rjump;

vector<int> dp;

int result(int k, vector<int> &vis) {
	if( dp[k] ) return dp[k];
	// --
	int res = 1;
	vis[k] = 1;
	for(auto &rleg : rjump[k]) {
		if(vis[rleg]) continue;
		vis[rleg] = 1;
		res += result(rleg, vis);
	}
	dp[k] = res;
	return res;
}

int main(){
	cin >> n >> k;
	// --
	dp	= vector<int> (n + 1, 0);
	jump	= vector<int> (n + 1, 0);
	rjump	= vector<vector<int>> (n + 1, vector<int> ());
	for(int i = 1; i <= n; i++) {
		int v;
		cin >> v;
		jump[i]	= v;
		rjump[v].push_back(i);
	}
	// --
	for(int i = 1; i <= n; i++) {
		vector<int> vis (n+1, 0);
		printf("%d\n", result(i, vis));
	}
}
