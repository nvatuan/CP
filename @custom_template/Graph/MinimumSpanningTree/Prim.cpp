/*
//problem: https://www.spoj.com/problems/MST/
//sample input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40
//sample output:
17
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

llong Prim(int& n, vector<vector<pair<int, llong>>>& G) {
    typedef pair<llong, int> Elem;
    priority_queue< 
        Elem, vector<Elem>, greater<Elem>
    > pq;

    pq.push({0LL, 0});
    llong mst=0;

    unordered_map<int, int> visited;
    int cnt=0;

    while (not pq.empty()) {
        llong cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue;
        else {
            cnt++;
            visited[cur] = 1;
        }

        mst += cost;

        for (auto &p : G[cur]) {
            int nxt = p.first;
            llong cst = p.second;
            pq.push({cst, nxt});
        }
    }
    if (cnt < n) return -1;
    else return mst;
}

int main() {
    int N, M;
    vector<vector< pair<int, llong> >> G;

    cin >> N >> M;
    G.resize(N, vector<pair<int, llong>>());

    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    cout << Prim(N, G) << endl;
}