#include <bits/stdc++.h>
using namespace std;

const int __multitest = 1;
const int __debugmode = 1;
#define db if (__debugmode)

template<typename T>
T In() { T x; cin >> x; return x; }

// --
int n, x;
vector<vector<int>> edgeList;

vector<int> heap;
vector<int> visited;
vector<int> subnodes;
void get_subnodes(int x) {
    int _subnodes = 1;
    visited[x] = true;
    for (const int& i : edgeList[x]) {
        if (!visited[i]) {
            get_subnodes(i);
            _subnodes += subnodes[i];
        }
    }
    subnodes[x] = _subnodes;
}

void solve() { 
    cin >> n >> x;
    x--;
    edgeList.clear();
    edgeList.resize(n, vector<int>(0));
    for (int a, b, i = 1; i < n; i++) {
        cin >> a >> b;
        a--, b--;
        edgeList[a].push_back(b);
        edgeList[b].push_back(a);
    }
    heap.clear();
    subnodes.clear(); subnodes.resize(n, 0);
    visited.clear(); visited.resize(n, 0);
    get_subnodes(x);
    //
    /*
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " has " << subnodes[i] << " subnodes." << endl;
    }
    */
    // --
    if (edgeList[x].size() <= 1) {
        cout << "Ayush" << endl;
    } else {
        cout << ((subnodes[x]) % 2 ? "Ashish" : "Ayush") << endl;
    }
}

int main() {
    for (int t = In<int>(); t; t--) solve();
}