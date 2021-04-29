#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SIZE = (int)(1e5)+10;
int trace[SIZE];

int n;
int c[SIZE];
vector<int> adj[SIZE];

int good[SIZE];
int currColor[SIZE];
void dfs(int v, int parent=-1) {
    if (currColor[c[v]] == 0) {
        good[v] = 1;
    }
    currColor[c[v]]++;

    for (int nxt : adj[v]) {
        if (nxt != parent)
            dfs(nxt, v);
    }
    currColor[c[v]]--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> c[i];

    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
    for (int i=0; i<n; i++) {
        if (good[i]) cout << i+1 << '\n';
    }
}
