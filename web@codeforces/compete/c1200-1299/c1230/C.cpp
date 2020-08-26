#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int n, m;

vector< pair<int, int> > edges;

int numOnV[8];

int ans = 0;

void backtrack(int i) {
    if(i == n) {
        set< pair<int, int> > dup;
        for(auto &p : edges) {
            dup.insert( {min(numOnV[p.first], numOnV[p.second]), max(numOnV[p.first], numOnV[p.second])} );
            // dup.insert( numOnV[p.first]*10+numOnV[p.second] );
            // dup.insert( numOnV[p.first]+numOnV[p.second]*10 );
        }
        ans = max(ans, int(dup.size()));
        // if( dup.size() == 21 ) {
        //     for(int i = 0; i < n; i++) cout << numOnV[i] << ' ';
        //     cout << endl;
        // }
    } else {
        for(int v = 1; v <= 6; v++) {
            numOnV[i] = v;
            backtrack(i+1);
        }
    }
}

int main() {
    cin >> n >> m;
    //--
    edges = vector< pair<int, int> > (m, pair<int, int>() );
    for(int a, b, i = 0; i < m; i++) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        edges[i].F = a-1;
        edges[i].S = b-1;
    }
    //--
    backtrack(0);
    cout << ans;
}