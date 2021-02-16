#include <bits/stdc++.h>
using namespace std;

class Disjoint {
    public:
        int n;
        vector<int> root, sz;
        Disjoint(){}
        Disjoint(int nn) {
            n = nn;
            root = vector<int> (nn);
            for (int i=0; i<n; i++) root[i] = i;
            sz = vector<int> (nn, 1);
        }

        int GetRoot(int x) {
            while (x != root[x]) {
                x = root[x] = root[root[x]];
            }
            return x;
        }
        int Union(int a, int b) {
            int ra = GetRoot(a);
            int rb = GetRoot(b);
            if (ra == rb) return 0;
            if (sz[ra] > sz[rb]) {
                root[rb] = ra;
                sz[ra] += sz[rb];
            } else {
                root[ra] = rb;
                sz[rb] += sz[ra];
            }
            return 1;
        }
        vector<int> GetRootDistinctSet() {
            vector<int> seen (n, 0);
            vector<int> rid;
            for (int i=0; i<n; i++) {
                int ri = GetRoot(i);
                if (seen[ri] == 0) {
                    seen[ri] = 1;
                    rid.push_back(ri);
                }
            }
            return rid;
        }
};

int n, q;
queue<tuple<int, int, int>> edges;

const int N = (int)(2e5)+10;
int age[N], check[N];

vector<int> rid;
int rid_sz;

Disjoint DS;

int main() {
    cin >> n >> q;
    DS = Disjoint (n);

    for (int i=0; i<q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        DS.Union(a-1, b-1);
        edges.push(make_tuple(a, b, c));
        edges.push(make_tuple(b, a, -c));
    }

    for (int i=0; i<n; i++) {
        if (DS.root[i] == i) {
            check[i+1] = 1;
            age[i+1] = 0;
        }
    }

    int timeout = edges.size();
    int pos = 1;
    while (!edges.empty()) {
        auto tp = edges.front();
        edges.pop();
        int fr = get<0>(tp);
        int to = get<1>(tp);
        int cs = get<2>(tp);

        if (!check[fr]) {
            edges.push(tp);
            timeout--;
        } else {
            timeout = edges.size();
            if (!check[to]) {
                check[to] = 1;
                age[to] = (age[fr] + cs);
            } else {
                if (age[fr]+cs == age[to]) {
                } else {
                    pos = 0;
                    break;
                }
            }
        }
        if (timeout == -5) {
            pos = 0;
            break;
        }
    }

    if (!pos) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    rid = DS.GetRootDistinctSet();
    rid_sz = rid.size();
    vector<int> mx (n, INT_MIN), mn (n, INT_MAX);
    for (int i=0; i<n; i++) {
        int ri = DS.GetRoot(i);
        mx[ri] = max(mx[ri], age[i+1]);
        mn[ri] = min(mn[ri], age[i+1]);
    }

    ans = 0;
    for (int i=0; i<n; i++) {
        if (mx[i] != INT_MIN && mn[i] != INT_MAX)
            ans = max(ans, mx[i] - mn[i]);
    }
    pos &= (ans <= 100);
    if (pos == 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}