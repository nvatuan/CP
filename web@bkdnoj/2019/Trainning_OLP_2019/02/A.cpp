#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> edge;
vector<vector<int>> adjM;

int main() {
    cin >> n >> m;   
    //edge = vector<vector<int>> (n, vector<int>());
    adjM = vector<vector<int>> (n, vector<int>(n, 0));
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        //edge[u].push_back(v);
        adjM[u][v] = 1;
        //adjM[v][u] = 1;
        //edge[v].push_back(u);
    }
    // --
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            //
            long long adjToIJ = 0;
            for(int k = 0; k < n; k++) {
                //printf("(%d and %d) <- %d is %d\n", i, j, k, (adjM[i][k] && adjM[j][k]));
                adjToIJ += (adjM[i][k] && adjM[j][k]);
            }
            //
            ans += ((adjToIJ * (adjToIJ-1))/2);
        }
    }
    //
    cout << ans;
}