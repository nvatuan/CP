/*
//problem: https://www.spoj.com/problems/MST/
//sample input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40
//sample output:
17
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

typedef long long llong;

llong Kruskal(int N, vector< pair<llong, pair<int, int> > >& E) {
    sort(E.begin(), E.end());

    DisjointSetUnion dsu;
    dsu.init(N);

    llong mst = 0;
    int cnt = 1;

    for (pair<llong, pair<int, int> >& e : E) {
        llong cst = e.first;
        int a = e.second.first, b = e.second.second;

        if (not dsu.is_connected(a, b)) {
            mst += cst;
            dsu.try_union(a, b);
            cnt++;
        }
    }
    if (cnt == N) return mst;
    return -1;
}

int main() {
    int N, M;
    vector< pair<llong, pair<int, int>> > E;

    cin >> N >> M;

    E.resize(M);

    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        E[i] = make_pair(c, make_pair(a, b));
    }

    cout << Kruskal(N, E) << endl;
}