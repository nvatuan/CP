/*
    template used by Kruskal.cpp
 */
#include <bits/stdc++.h>
using namespace std;

struct DisjointSetUnion {
    int n; vector<int> root, size;
    void init(int k) {
        n = k;
        root.resize(n); for (int i=0; i<n; i++) root[i] = i;
        size.assign(n, 1);
    }

    int get_root(int x) {
        while (x != root[x]) { x = root[x] = root[root[x]]; }
        return x;
    }

    int try_union(int a, int b) {
        int ra = get_root(a), rb = get_root(b);
        if (ra == rb) return 0;

        if (size[ra] < size[rb]) {
            root[ra] = rb;
            size[rb] += size[ra];
        } else {
            root[rb] = ra;
            size[ra] += size[rb];
        }
        return 1;
    }

    int is_connected(int a, int b) {
        int ra = get_root(a), rb = get_root(b);
        return (ra == rb);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    DisjointSetUnion dsu;
    dsu.init(N);

    for (int i=0; i<Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << dsu.is_connected(u, v) << '\n';
        } else {
            dsu.try_union(u, v);
        }
    }

}