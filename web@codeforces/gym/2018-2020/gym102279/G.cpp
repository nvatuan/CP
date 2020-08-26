#include <bits/stdc++.h>
using namespace std;

int N;
int M;

vector< int > V;

int mdepth = 0;
int vert1 = 0;

void dfs(int x, vector< vector<int> > &E, vector<int> &V, int depth) {
    if(V[x]) return;
    V[x] = 1;
    //
    if(depth > mdepth) {
        mdepth = depth;
        vert1 = x;
    }
    //
    for(auto &v : E[x]) {
        dfs(v, E, V, depth+1);
    }
}

int main() {
    cin >> N;

    vector< vector<int> > e1 (N, vector<int>());
    for(int a, b, i = 1; i < N; i++) {
        cin >> a >> b;
        a--, b--;
        e1[a].push_back(b);
        e1[b].push_back(a);
    }

    cin >> M;

    vector< vector<int> > e2 (M, vector<int>());
    for(int a, b, i = 1; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        e2[a].push_back(b);
        e2[b].push_back(a);
    }
    // --
    V = vector< int > (N, 0);
    mdepth = 0;
    dfs(0, e1, V, 1);
    
    V = vector< int > (N, 0);
    mdepth = 0;
    dfs(vert1, e1, V, 1);
    int mdpth1 = mdepth;
    //
    V = vector< int > (M, 0);
    mdepth = 0;
    dfs(0, e2, V, 1);
    V = vector< int > (M, 0);

    mdepth = 0;
    dfs(vert1, e2, V, 1);
    int mdpth2 = mdepth;
    //--
    // cout << "@" << vert1 << endl;
    // cout <<'\t' << mdpth1 << ' ' << mdpth2 << endl;
    cout << (mdpth1 > ((mdpth2+1)/2) ? "GGEZ" : "FF");
}