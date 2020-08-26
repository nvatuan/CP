#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;
const int __DEBUGMODE = 0;
#define db if(__DEBUGMODE)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- solve
int n, m;
int node[200001];

class Edge {
    int u, v;
    int directed;
    Edge() {}
    Edge(int x, int y, int d) : u(x), v(y), directed(d) {}
};
Edge edge[200001];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].directed);
    }
}

// --
int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}