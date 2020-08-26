#include <bits/stdc++.h>
using namespace std;

const int SIZE = (int(3e5) + 5);
int n, q;

vector<int> Edge[SIZE], Tree[SIZE];

void input();

int depth[SIZE];

void buildTree() {
    fill(depth, depth + n, -1);

    queue<pair<int, int>> Q; // first is Node, second is depth;
    Q.push({0, 0});
    while (not Q.empty()) {
        int nd = Q.front().first;
        int de = Q.front().second;
        Q.pop();
        depth[nd] = de;

        for (int& child : Edge[nd]) {
            if (depth[child] == -1) {
                Q.push({child, de + 1});
                Tree[nd].push_back(child);
            }
        }
    }
}

int binLifting[20][SIZE];

void buildBinLifting() {
    binLifting[0][0] = -1;
    for (int node = 0; node < n; node++) {
        for (int& child : Tree[node])
            binLifting[0][child] = node;
    }
    
    for (int lift = 1; lift < 20; lift++)
        for (int node = 0; node < n; node++) {
            if (binLifting[lift-1][node] == -1) binLifting[lift][node] = -1;
            else binLifting[lift][node] = binLifting[lift-1][binLifting[lift-1][node]];
        }
}

int moveUp(int x, int step) {
    for (int lift = 20-1; lift >= 0; lift--) {
        if (step >= (1 << lift)) {
            step -= (1 << lift);
            x = binLifting[lift][x];
        }
    }
    return x;
}

int LCA(int u, int v) {
    if (depth[u] != depth[v]) {
        int* Lift = &u;
        if (depth[u] < depth[v]) Lift = &v;
        *Lift = moveUp(*Lift, abs(depth[u] - depth[v]));
    }
    assert(depth[u] == depth[v]);

    if (u == v) return u;

    for (int pwr2 = 20-1; pwr2 >= 0; pwr2--) {
        int mU = moveUp(u, (1<<pwr2));
        int mV = moveUp(v, (1<<pwr2));
        if (mU != mV) u = mU, v = mV;
    }
    assert(binLifting[0][u] == binLifting[0][v]);
    return binLifting[0][u];
}

int moveFromFirstToSecond(int first, int second, int maxStep) {
    int lca = LCA(first, second);

    if (first != lca) {
        if (maxStep < depth[first] - depth[lca]) return moveUp(first, maxStep);
        maxStep -= (depth[first] - depth[lca]);
        first = lca;
    }

    if (maxStep < depth[second] - depth[lca]) return moveUp(second, depth[second] - depth[lca] - maxStep);
    return second;
}

int main() {
    input();
    buildTree();
    buildBinLifting();

    for (cin >> q; q; q--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        printf("%d\n", moveFromFirstToSecond(a, b, c) + 1);
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        Edge[a-1].push_back(b-1);
        Edge[b-1].push_back(a-1);
    }
}