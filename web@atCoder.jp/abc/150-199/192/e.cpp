#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;

struct Edge {
    int to, t, k;
    Edge() {}
    Edge(int b, int c, int d) : to(b), t(c), k(d) {}

    bool operator<(Edge& e) {
        return t < e.t;
    }
};
vector<vector<Edge>> G;

int main(){
    cin >> n >> m >> x >> y;
    x--, y--;

    G.assign(n, vector<Edge> ());

    for (int i=0; i<m; i++) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        a--, b--;
        G[a].push_back(Edge(b, t, k));
        G[b].push_back(Edge(a, t, k));
    }

    typedef pair<long long, int> PQElem;

    priority_queue<
        PQElem, vector<PQElem>, greater<PQElem>
    > pq;
    unordered_map<int, int> visited;

    pq.push(make_pair(0LL, x));

    long long ans = LLONG_MAX;

    while (not pq.empty()) {
        long long time = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        //fprintf(stderr, "TIME=%lld, CUR=%d\n", time, cur);

        if (cur == y) {
            ans = min(ans, time);
            continue;
        }
        if (visited[cur]) continue;
        visited[cur] = 1;

        for (Edge& e : G[cur]) {
            long long arrive_time = (time + e.k-1)/e.k*e.k + e.t;
            pq.push(make_pair(arrive_time, e.to));
        }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    return 0;
}