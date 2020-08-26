#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> edge;
vector<vector<int>> adjM;

vector<set<int>> S;

int main() {
    cin >> n >> m;   
    edge = vector<vector<int>> (n, vector<int>());
    adjM = vector<vector<int>> (n, vector<int>(n, 0));
    S   = vector<set<int>> (n, set<int>());
    while(m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        //edge[u].push_back(v);
        S[u].insert(v);
        adjM[u][v] = 1;
    }
    // --
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            //
            vector<int> temp (n, 0);
            auto it = set_intersection(S[i].begin(), S[i].end(), S[j].begin(), S[j].end(), temp.begin());
            temp.resize(it - temp.begin());
            int adjToIJ = temp.size();
            //
            ans += ((adjToIJ * (adjToIJ-1))/2);
        }
    }
    //
    cout << ans;
}