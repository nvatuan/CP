#include <bits/stdc++.h>
using namespace std;

string Hash(vector<int> edges) {
    string H ("");
    for(auto &to : edges) H += to_string(to);
    sort(H.begin(), H.end());
    return H;
}

int not_completely_disconnected(vector<int> Set, vector<int> first_connects_to) {
    unordered_map< int, int > exist;
    for(auto &v : Set) exist[v] = 1;
    // --
    for(auto &v : first_connects_to)
        if(exist[v]) return 1;
    // --
    return 0;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > edgeList(n, vector<int>());
    //
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edgeList[a].push_back(b);
        edgeList[b].push_back(a);
    }
    // --
    int no_edge_fl = 0;
    map< string, vector<int> > Map;
    for(int v = 0; v < n; v++) {
        string h = Hash(edgeList[v]);
        no_edge_fl = (h == "");
        // cerr << v << " -> " << h << endl;
        Map[h].push_back(v);
    }
    // -- corner case 1
    if(Map.size() != 3) {
        cout << -1;
        return 0;
    }
    // -- corner case 2
    if(no_edge_fl) {
        cout << -1;
        return 0;
    }
    // -- corner case 3
    for(auto &p: Map) {
        // cerr << "Set: ";
        // for(int &v : p.second) cerr << v << ' ';
        // cerr << endl;

        // check for connectivity in each set
        if( not_completely_disconnected(p.second, edgeList[p.second[0]]) ) {
            cout << -1;
            return 0;
        }
    }
    // -- answer found
    vector<int> vset (n, 0);
    int s = 1;
    for(auto &p : Map) {
        for(auto &v : p.second) vset[v] = s;
        s++;
    }
    for(int &v : vset) cout << v << ' ';
}