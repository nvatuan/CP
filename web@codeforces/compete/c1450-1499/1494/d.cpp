#include <bits/stdc++.h>
using namespace std;

const int MAX_SUPERVISOR = 2048;

struct DisjointSetUnion {
    int n; vector<int> root, size;
    void init(int k) {
        n = k;
        root.resize(n); for (int i=0; i<n; i++) root[i] = i;
        size.assign(n, 1);
        RtoK.assign(MAX_SUPERVISOR, 0);
        KtoR.assign(MAX_SUPERVISOR, 0);
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

int n;
int s[515][515];
int m[515][515];

int supervisor[MAX_SUPERVISOR];
int salary[MAX_SUPERVISOR];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        m[i][i] = 1;
        for (int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }

    priority_queue<
        tuple<int, int, int>, vector<int, int, int>, greater<tuple<int, int, int>>
    > pq;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                salary[i] = s[i][j];
                continue;
            }
            pq.push_back(make_tuple(s[i][j], i, j));
        }
    }

    DisjointSetUnion ds;
    ds.init(n);

    for (int i=0; i<MAX_SUPERVISOR; i++) supervisor[i] = i;

    int k = n;

    int union_cnt = n;

    unordered_map<int, int> rtok;
    for (int i=0; i<n; i++) rtok[i] = i;

    while (union_cnt > 1) {
        // Finding next lowest supervisor
        int next_salary = get<0>(pq.top());
        vector<pair<int, int>> lca_subs;

        while (!pq.empty() && next_salary == get<0>(pq.top())) {
            int tmp, u, v; tie(tmp, u, v) = pq.top();
            pq.pop();

            lca_subs.push_back({u, v});
        }

        vector<pair<int, int>> direct_subs;
        for (auto p : lca_subs) {
            int r1 = ds.get_root(p.first);
            int r2 = ds.get_root(p.second);
            int k1 = rtok[r1];
            int k2 = rtok[r2];
            if (ds.try_union(r1, r2)) {
                union_cnt--;
                direct_subs.push_back({k1, k2});
            }
        }
        
        unordered_set<int> r;
        for (auto p : direct_subs) {
            int rt = ds.get_root(p.first);
            if (r.find(rt) == r.end()) {
                r.insert(rt)k
                supervisor[p.first] = k;
                supervisor[p.second] = k;
                salary[k] = next_salary;
                rtok[rt] = k;
                k++;
            }
        }
    }
}