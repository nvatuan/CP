#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> tree;

int main() {
    cin >> n;
    tree = vector<vector<int>> (n, vector<int>(0));

    map<pair<int, int>, int> edge_id;
    for (int a, b, i=1; i<n; i++) {
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);

        edge_id[{a, b}] = i-1;
        edge_id[{b, a}] = i-1;
    }

    queue<int> Q;
    Q.push(0);
    map<int, int> vis;

    int max_degree = 0;
    vector<int> ans (n-1, 0);

    while (Q.size() > 0) {
        int front = Q.front();
        Q.pop();

        if (vis[front]) continue;
        vis[front] = 1;

        max_degree = max(max_degree, (int) tree[front].size());
        int mex = 0;
        unordered_map<int, int> mex_table;

        for (int child : tree[front]) {
            mex_table[ans[edge_id[{child, front}]]] = true;
            if (vis[child]) continue;
            Q.push(child);
        }
        
        for (int child : tree[front]) {
            if (ans[edge_id[{front, child}]] == 0) {
                while (mex_table[mex]) mex += 1;
                ans[edge_id[{front, child}]] = mex;
                mex++;
            }
        }
    }

    cout << max_degree << '\n';
    for (int i=0; i<n-1; i++) {
        cout << ans[i] << '\n';
    }
}