#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int N, M;

vector<int>         dg  (501, 0);
vector<vector<int>> a   (501, vector<int>(501, 0));

bool possible(int K, vector<int> dg, vector<vector<int>> a) {
    queue< pair<int, int> > noEdge;
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            if( !a[i][j] ) noEdge.push( {i, j} );
    // --
    int counter = 0;
    while( counter < int(noEdge.size()) ) {
        pair<int, int> p = noEdge.front();
        noEdge.pop();
        // --
        if( dg[p.first] + dg[p.second] >= K ) {
            //printf("edge %d to %d valid.\n", p.first, p.second);
            //
            a[p.first][p.second] = a[p.second][p.first] = 1;
            dg[p.first]++;
            dg[p.second]++;
            //
            counter = 0;
        } else {
            noEdge.push(p);
            counter++;
        }
    }
    // --
    return (noEdge.size() == 0);
}

int main() {
    cin >> N >> M;
    for(int u, v, i = 0; i < M; i++) {
        cin >> u >> v;
        u--; v--;
        dg[u]++; dg[v]++;
        a[u][v] = a[v][u] = 1;
    }  
    for(int i = 0; i < N; i++) a[i][i] = 1;
    // --
    int L = 0, R = N*2;
    while ( L < R ) {
        int k = (L + R + 1)/2;
        if( possible(k, dg, a) ) {
            L = k;
        } else {
            R = k-1;
        }
    }
    //
    cout << R;
}