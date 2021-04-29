#include <bits/stdc++.h>
using namespace std;

#define INF ((int)(1e9))

class Graph {
public:
    int n, m, s, t;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    Graph(int n, int m, int s, int t, const vector<vector<int>>& a, const vector<vector<int>>& c) {
        std::tie(this->n, this->m, this->s, this->t) = make_tuple(n, m, s, t);
        this->adj = a;
        this->capacity = c;
    }
    
    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});
    
        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();
    
            for (int next : adj[cur]) {
                if (parent[next] == -1 && capacity[cur][next]) {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
    
        return 0;
    }
    
    int maxFlow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;
    
        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }
    
        return flow;
    }
};
int n, m, s, t;
vector<vector<int>> a, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> t;
    s--, t--;
    a.resize(n);
    c.resize(n, vector<int>(n, 0));

    for (int i=0; i<m; i++) {
        int u,v,cs; cin >> u >> v >> cs;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v] = c[v][u] = cs;
    }

    Graph G(n,m,s,t,a,c);
    cout << G.maxFlow(G.s, G.t) << endl;
}
