#include <bits/stdc++.h>
using namespace std;

vector<vector< pair<int, int> >> edge;
int N;

int deg[int(1e5) + 3];
int color[int(1e5) + 3];
int ans[int(1e5) + 3];

int maxAns = 0;

void dfs(int x) {
    int CL = 0;
    for(const pair<int, int> &P : edge[x]) {
        if(color[P.first]) continue;
        //
        do {
            CL++;
        } while(CL == color[x]);
        //
        color[P.first] = CL;
        ans[P.second] = CL;
        maxAns = max(maxAns, CL);
        dfs(P.first);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //
    cin >> N;
    edge.resize( N+1, vector<pair<int, int>> () );
    for(int a, b, i = 1; i < N; i++) {
        cin >> a >> b;
        edge[a].push_back( {b, i} );
        edge[b].push_back( {a, i} );
        deg[a]++;
        deg[b]++;
    }
    for(int i = 1; i <= N; i++)
        if(deg[i] == 1) {
            color[i] = -1;
            dfs(i);
            break;
        }
    //
    printf("%d\n", maxAns);
    for(int i = 1; i < N; i++) printf("%d\n", ans[i]);
}
