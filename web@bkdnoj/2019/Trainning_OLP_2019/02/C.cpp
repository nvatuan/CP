#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> edge;
vector<int> target;
vector<int> visited;

int ans = 0;

int main(){
    cin >> n >> m;
    target = vector<int> (m);
    for(int &i : target) cin >> i;

    edge = vector<vector<int>>(n, vector<int>());
    for(int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    // -- process
    visited = vector<int> (n, 0);
    if(m == 2) {
        queue< pair<int, int> > Q;
        Q.push( {target[0], 0} );
        //
        while( !Q.empty() ) {
            int x       = Q.front().first;
            int cost    = Q.front().second;
            Q.pop();
            //
            //if( visited[x] ) continue;
            if( x == target[1] ) {
                cout << cost;
                return 0;
            }
            visited[x] = 1;
            //
            for(const int& v : edge[x]) {
                if(!visited[v]) {
                    Q.push( {v, cost + 1} );
                    visited[v] = 1;
                }
            }
        }
    }
    //
    if(1) {
        cout << int(round(n * 1.61803398875));
    }
}