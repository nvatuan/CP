#include <bits/stdc++.h>
using namespace std;

int n, m;
long long cost[16][16];
int adj[16][16];

int HamiltonianMincost() {
	vector< vector<long long> > DP ( n, vector<long long> (1<<n, INT_MAX) );
	vector< vector<int> >       start ( n, vector<int> (1<<n, 0) );
	//
	for(int i = 0; i < n; i++) {
		DP[i][1 << i] = 0;
	}
	for(int i = 0; i < n; i++) {
		start[i][1 << i] = i;
	}
	//
	for(int subset = 0; subset < (1<<n); subset++) {
		for(int e = 0; e < n; e++)
		if( (1 << e) && subset ) {
			for(int ex = 0; ex < n; ex++)
			if( ((1 << ex) && subset) && (e != ex) ) {
				bool logic = (DP[e][(subset)^(1 << ex)] != INT_MAX) && (adj[e][ex]);
				if(!logic) continue;
				if(DP[ex][subset] > DP[e][subset^(1 << ex)] + cost[e][ex]) {
					DP[ex][subset]    = DP[e][subset^(1 << ex)] + cost[e][ex];
					start[ex][subset] = start[e][subset^(1<<ex)];
				}
			}
		}
	}
	//
	long long ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		ans = ( adj[i][start[i][(1<<n)-1]] ? (min(ans, DP[i][(1<<n)-1]) + cost[i][start[i][(1<<n)-1]]) : ans);
	}
	return (ans == INT_MAX ? -1 : ans);
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			cost[i][j] = ( i == j ? 0 : INT_MAX );
	//
	for(int a,b,x,i = 0; i < m; i++) {
		cin >> a >> b >> x;
		cost[a][b] = min(cost[a][b], x*1LL);
		adj[a][b]  = 1;
		assert(a != b);
	}
	//
	cout << HamiltonianMincost();
}
