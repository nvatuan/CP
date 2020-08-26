#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/FLVn1Sc504/contest/274834/problem/K
// vn.spoj TJALG

class Tarjan {
// Calculate numbers of SCC, marking SCCs.
// Using 0-indexed graph. Graph is directed and could be disconnected.
public:
    int N, M; // N: number of nodes, M: number of edges
    vector<vector<int>> G; // G: Graph
    
    void readGraph() {
        cin >> N >> M;
        G.resize(N, vector<int>());
        for (int a, b, i = 0; i < M; i++) {
            cin >> a >> b;
            G[a-1].push_back(b-1);
        }
    }  
    
    // Solve
    int scc, idCount;

    vector<int> id, lowLink, onStack;
    stack<int> Stack;

    void dfs(int x) {
        id[x] = lowLink[x] = ++idCount;
        Stack.push(x); onStack[x] = true; 

        for (int& next : G[x]) {
            if (!id[next]) dfs(next);
            if (onStack[next])
                lowLink[x] = min(lowLink[x], lowLink[next]);
        }

        if (id[x] == lowLink[x]) {
            scc++;
            while (!Stack.empty() && lowLink[Stack.top()] == lowLink[x]){ 
                onStack[Stack.top()] = false;
                Stack.pop();
            }
        }
    }

    void solve() {
        scc = idCount = 0;
        id.resize(N, 0); lowLink.resize(N, 0), onStack.resize(N, 0);
        for (int i = 0; i < N; i++) if (!id[i]) dfs(i);

        printf("%d\n", scc);
    }
};
/*  Tarjan tj;
    tj.readGraph();
    tj.solve();
*/


int main() {
    Tarjan tj;
    tj.readGraph();
    tj.solve();
}