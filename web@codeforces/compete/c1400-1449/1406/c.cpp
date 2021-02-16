#include <bits/stdc++.h>
using namespace std; 

int n;
vector<vector<int>> tree;

int subtree_size[int(1e5) + 10];

void dfs(int u, int p = -1) {
    int stree = 1;
    for (int child : tree[u]) 
        if (child != p) {
            dfs(child, u);
            stree += subtree_size[child];
        }
    subtree_size[u] = stree;    
}

pair<int, int> get_leaf(int node, int parent) {
    while (true) {
        bool is_leaf = true;
        for (int child : tree[node])
            if (child != parent) {
                parent = node;
                node = child;
                is_leaf = false;
                break;
            }
        if (is_leaf) return make_pair(node, parent);
    }
    assert(false);
    return make_pair(-1, -1);
}

void solve() {
    cin >> n;
    tree = vector<vector<int>> (n, vector<int>(0));
    for (int u, v, i=1; i<n; i++) {
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    fill(subtree_size, subtree_size + n, 0);
    dfs(0);
    //cerr << "iter centroids..\n";

    vector<int> centroids;
    int parent = -1;
    int travel = 0;
    while (true) {
        // get max components
        int max_component = n - subtree_size[travel];
        int max_child_component = -1;
        for (int child : tree[travel]) {
            if (child != parent) {
                max_component = max(max_component, subtree_size[child]);
                if (max_child_component == -1) max_child_component = child;
                else {
                    if (subtree_size[max_child_component] < subtree_size[child])
                        max_child_component = child;
                }
            }
            //cerr << "Current = " << travel << " | Child = " << child << '\n';
        }
        // is centroid
        if (max_component <= n/2) centroids.push_back(travel);
        //cerr << travel << ' '<< parent << "->" << max_child_component << endl;

        // check if max_child_component has a potential centroid (its size ~= n/2)
        if (subtree_size[max_child_component] >= n/2) {
            // go toward max child component
            parent = travel;
            travel = max_child_component;
        } else break;
    }

    //cerr << "Centroids: ";
    //for (int c : centroids) cerr << c+1 << ' '; cerr << endl;

    assert(centroids.size() <= 2);
    // solution
    if (centroids.size() == 1) {
        //cout << "1 2\n1 2\n";
        cout << 1 << " " << tree[0][0] + 1 << '\n';
        cout << 1 << " " << tree[0][0] + 1 << '\n';
    } else {
        pair<int, int> leaf_edge = get_leaf(centroids[1], centroids[0]);
        //cout << centroids[0]+1 << ' ' << centroids[1]+1 << '\n';
        //cout << centroids[0]+1 << ' ' << leaf_edge.first + 1 << '\n';
        cout << leaf_edge.first+1 << ' ' << leaf_edge.second+1 << '\n';
        cout << centroids[0]+1 << ' ' << leaf_edge.first+1 << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}