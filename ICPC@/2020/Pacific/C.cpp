#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;

int main() {
    cin >> N >> M;
    G.resize(N, vector<int>());
    for (int a, b, i=0; i<M; i++) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    unordered_map<int, int> vist;

    int ans = -1;
    while (!Q.empty()) {
        int node = Q.front().first;
        int dist = Q.front().second;
        Q.pop();

        if (vist[node]) continue;
        vist[node] = 1;

        if (node == N-1) {
            ans = dist;
            break;
        }

        for (int nxt : G[node]) Q.push({nxt, dist+1});
    }
    
    cout << ans - 1 << endl;
}