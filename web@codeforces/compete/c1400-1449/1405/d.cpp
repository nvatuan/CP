#include <bits/stdc++.h>
using namespace std;

int n;
int a, da, b, db;

vector<vector<int>> tree;

int _furthest = 0;
int _dist = 0;
void dfs(int u, int dist, int p = -1) {
    if (p == -1) {
        _furthest = _dist = 0;
    }
    for (int next_node : tree[u])
        if (next_node != p)
            dfs(next_node, dist + 1, u);
    
    if (_dist < dist) {
        _dist = dist;
        _furthest = u;
    }
}

int get_diameter() {
    dfs(0, 0);
    dfs(_furthest, 0);
    return _dist;
}

int win_on_first_turn() {
    vector<int> seen (n, 0);
    queue<pair<int, int>> q;
    q.push({a, 0});

    while (not q.empty()) {
        int curr_node = q.front().first;
        int curr_cost = q.front().second;
        q.pop();

        if (curr_cost > da) continue;
        if (seen[curr_node]) continue;
        seen[curr_node] = 1;

        if (curr_node == b) return true;

        for (int next_node : tree[curr_node])
            q.push({next_node, curr_cost+1});
    }
    return false;
}

void solve() {
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    
    tree = vector<vector<int>> (n, vector<int>(0));
    
    for (int a, b, i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    int dia = get_diameter();
    
    //cout << "Win on first turn: " << std::boolalpha << win_on_first_turn() << endl;
    string ans[] = {"Bob\n", "Alice\n"};
    cout << ans[(min(dia, db) <= da*2) or win_on_first_turn()];    
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}