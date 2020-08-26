#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > edgeList;
vector< vector<int> > rEdgeList;

void dfs(int node, vector<int> &V, stack<int> &topo, vector<vector<int>> &E) {
	if( V[node] ) return;
	V[node] = 1;
	//
	for(auto &v : E[node])
		dfs(v, V, topo, E);
	topo.push(node);
}

void Korasaju(int node, vector<int> &V, vector<vector<int>> &E) {
	if(V[node]) return;
	V[node] = 1;
	//
	for(int &v : E[node]) Korasaju(v, V, E);
}

int main() {
	int n, m, T;
	for(cin >> T; T; T--) {
		scanf("%d%d", &n, &m);
		edgeList	= vector< vector<int> > (n, vector<int>());
		rEdgeList	= vector< vector<int> > (n, vector<int>());
		//
		for(int a, b; m; m--) {
			scanf("%d%d", &a, &b);
			edgeList[a].push_back(b);
			rEdgeList[b].push_back(a);
		}
		// --
		stack<int> topoOrder;
		// -- get topological order
		vector<int> visited(n, 0);
		for(int i = 0; i < n; i++) 
			if( !visited[i] ) dfs(i, visited, topoOrder, edgeList);
		// 
		int ans = 0;
		// -- process topological order
		visited = vector<int> (n, 0);
		while( !topoOrder.empty() ) {
			int source = topoOrder.top();
			topoOrder.pop();
			//
			if( !visited[source] ) {
				ans++;
				Korasaju(source, visited, rEdgeList);
			}
		}
		//
		cout << ans << '\n';
	}
}