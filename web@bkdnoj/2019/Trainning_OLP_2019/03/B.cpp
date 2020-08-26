#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int n, m;
vector<vector<int64>> edge, cost;

pair<int,int> edgeList[30001];

int64 ans = LLONG_MAX;

int64 dijsktra() {
    priority_queue < pair<int, int64>, vector<pair<int, int64>>, greater<pair<int, int64>> > Q;
    Q.push({0, 0});
    //
    vector<int> visited (n, 0);
    while( !Q.empty() ) {
        int     node = Q.top().first;
        int64   C    = Q.top().second;
        Q.pop();
        // --
        if( node == n-1 ) {
            while( !Q.empty() ) Q.pop();
            return C;
        }
        if( visited[node] ) continue;
        visited[node] = 1;
        //
        for(const int & V : edge[node]) {
            Q.push( {V, C + cost[node][V]} );
        }
    }
    //
    return -1;
}

int main() {
    clock_t now = clock();
    //
    cin >> n >> m;
    edge = vector< vector<int64> > (n, vector<int64>());
    cost = vector< vector<int64> > (n, vector<int64>(n, INT_MAX));
    for(int u, v, c, i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
        //
        cost[u][u] = 0;
        cost[v][v] = 0;
        //
        cost[u][v] = c;
        cost[v][u] = c;   
        // --
        edgeList[i] = {u, v};
    }
    // --
    random_device rd;
    mt19937 g(rd());
 
    shuffle(edgeList, edgeList + m, g);
    // --
    for(int i = 0; i < m; i++) {
        int u = edgeList[i].first;
        int v = edgeList[i].second;
        int c = cost[u][v];
        //
        cost[u][v] = cost[v][u] = 0;
        ans = min(ans, dijsktra());
        cost[u][v] = cost[v][u] = c;
        //
        if( (clock() - now) >= (CLOCKS_PER_SEC + CLOCKS_PER_SEC*4/5) ) break;
    }
    cout << ans;
}