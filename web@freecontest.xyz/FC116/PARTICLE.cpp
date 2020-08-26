#include <bits/stdc++.h> 
using namespace std;
 
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int __MULTITEST = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// ================================================= SOLUTION =================================================
const int SIZE = 100001;

set<int> components[SIZE];
int n, q;

int bit[SIZE];
int root[SIZE];
int size[SIZE];

int Root(int x) {
    while (x != root[x]) x = root[x]; return x;
}
 
bool Union(int a, int b) {
    int rootA = Root(a);
    int rootB = Root(b);
    
    if (rootA == rootB) return false;
    if (size[rootA] < size[rootB]) {
        root[rootA] = rootB;
        size[rootB] += size[rootA];
        components[rootB].insert(components[rootA].begin(), components[rootA].end());
    } else {
        root[rootB] = rootA;
        size[rootA] += size[rootB];
        components[rootA].insert(components[rootB].begin(), components[rootB].end());
    }
}
bool sameUnion(int a, int b) {
    int rootA = Root(a);
    int rootB = Root(b);

    return (rootA == rootB);
}


void init() {
    for (int i = 0; i < n; i++) {
        root[i] = i; size[i] = 1;
        components[i].insert(i);
    }
}

void flip(int u, int v) {
    int ru = Root(u), rv = Root(v);
    int sel;
    
    if (components[ru].size() < components[rv].size()) sel = ru;
    else sel = rv;

    debug(components[sel]);
    for (const int& comp : components[sel]) bit[comp] *= -1;
}


void solve() {
    cin >> n >> q;
    init();

    char qtype; int u, v;
    for (int i = 0; i < q; i++) {
        cin >> qtype >> u >> v;
        u--, v--;
        switch (qtype) {
            case 'Q':
                if (sameUnion(u, v)) {
                    if (bit[u] * bit[v] == -1) {
                        cout << 'A' << '\n';
                    } else {
                        cout << 'R' << '\n';
                    }
                } else {
                    cout << '?' << '\n';
                }

                debug(vector<int> (bit, bit+n));
                break;
            case 'R':
                Union(u, v);
                if (!bit[u] && !bit[v]) {
                    bit[u] = 1;
                    bit[v] = 1;
                } else {
                    if (!bit[u]) bit[u] = bit[v];
                    else if (!bit[v]) bit[v] = bit[u];
                        else if (bit[u] != bit[v]) flip(u, v);
                }
                break;
            case 'A':
                Union(u, v);
                if (!bit[u] && !bit[v]) {
                    bit[u] = -1;
                    bit[v] = 1;
                } else {
                    if (!bit[u]) bit[u] = bit[v] * -1;
                    else if(!bit[v]) bit[v] = bit[u] * -1;
                            else if (bit[u] == bit[v]) flip(u, v);
                }
                break;
            default:
                assert("unexpected qtype" == "!");
        }
    }
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}