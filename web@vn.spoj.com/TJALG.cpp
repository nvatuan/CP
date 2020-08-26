#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> G, Gr;

void input() {
	scanf("%d%d", &N, &M);
	G.resize(N, vector<int>());
	Gr.resize(N, vector<int>());
	for (int a, b; M; M--) {
		scanf("%d%d", &a, &b);
		G[a-1].push_back(b-1);
		Gr[b-1].push_back(a-1);
	}
}

vector<int> order;

int visited[10001];
void dfs1(int x) {
	if (visited[x]) return;
	visited[x] = true;

	for (int nxt : G[x]) dfs1(nxt);
	order.push_back(x);
}
void dfs2(int x, int compo) {
	if (visited[x]) return;
	visited[x] = compo;

	for (int nxt : Gr[x]) dfs2(nxt, compo);
}

void korasaju(){
	fill(visited, visited + N, 0);
	for (int i = 0; i < N; i++)
		if (not visited[i]) dfs1(i);
	fill(visited, visited + N, 0);
	int scc = 0;
	for (int i = N-1; i >= 0; i--) {
		if (not visited[order[i]]) {
			scc++;
			dfs2(order[i], scc);
		}
	}
	printf("%d\n", scc);
}

int main() {
	input();
	korasaju();
}
