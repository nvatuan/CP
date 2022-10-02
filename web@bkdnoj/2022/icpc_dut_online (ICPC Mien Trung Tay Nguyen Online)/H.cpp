#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, m, d[N];
vector<array<int, 2>> adj[N];
int cost, cnt;

void dfs(int u, int p) {
    vector<int> ds;
    for (auto [v, w]: adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        ds.push_back(d[v] + w);
    }
    sort(ds.begin(), ds.end());
    while (!ds.empty() && ds.back() > cost) {
        ds.pop_back();
        cnt += 1;
    }
    int sz = (int) ds.size();
    while (sz >= 2 && ds[sz - 1] + ds[sz - 2] > cost) {
        ds.pop_back();
        cnt += 1;
        sz -= 1;
    }
    if (sz > 0)
        d[u] = ds.back();
    else
        d[u] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int l = 1, r = 1e9;
    while (l < r) {
        cost = (l + r) / 2;
        cnt = 0;
        dfs(0, -1);
        if (cnt < m) {
            r = cost;
        }
        else {
            l = cost + 1;
        }
    }

    cout << l;
    return 0;
}
