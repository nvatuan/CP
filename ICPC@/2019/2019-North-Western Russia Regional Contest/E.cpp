#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[200001];

vector< vector<int> > edge;

int dead[200001];

vector<int> vis;
void trim(int x) {
    if(vis[x]) return;
    vis[x] = 1;


    if( /*no city*/ ) dead[x] = 1;
}

int main() {
    cin >> n >> m;
    //
    edge.resize(n, vector<int> ());
    vis.resize(n, 0);
    //
    for(int a, b, i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }
    // --
    trim( c[0], vis);
}