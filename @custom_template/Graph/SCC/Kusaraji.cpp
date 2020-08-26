#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/FLVn1Sc504/contest/274834/problem/K
// vn.spoj TJALG

class Kusaraji {
// Calculate numbers of SCC, marking SCCs.
// Using 0-indexed graph. Graph is directed and could be disconnected.
public:
    int N, M;   // N: number of nodes, M: number of edges
    vector<vector<int>> G;  // G: original Graph
    vector<vector<int>> Gr; // Gr: reverse of Graph
    
    void readGraph() {
        cin >> N >> M;
        G.resize(N, vector<int>());
        Gr.resize(N, vector<int>());
        for (int a, b, i = 0; i < M; i++) {
            cin >> a >> b;
            G[a-1].push_back(b-1);
            Gr[b-1].push_back(a-1);
        }
    }

    // -- solve methods
    vector<int> marker;
    stack<int> order;
    int scc;

    void dfs1(int x) {
        marker[x] = true;
        for (int& next : G[x]) if (!marker[next]) dfs1(next);
        order.push(x);
    }
    void dfs2(int x, int label) {
        marker[x] = label;
        for (int& next : Gr[x]) if (!marker[next]) dfs2(next, label);
    }

    void solve() {
        marker.resize(N);
        while(!order.empty()) order.pop();

        fill(marker.begin(), marker.end(), 0);
        for (int i = 0; i < N; i++) if (!marker[i]) dfs1(i);

        scc = 0;
        fill(marker.begin(), marker.end(), 0);
        while (!order.empty()) {
            if (!marker[order.top()]) dfs2(order.top(), ++scc);
            order.pop();
        }

        printf("Number of SCCs are: ");
        printf("%d\n", scc);
        printf("Nodes in each SCC:\n");
        for (int com = 1; com <= scc; com++) {
            printf("> SCC#%d: {", com);
            for (int i = 0; i < N; i++) 
                if (marker[i] == com) printf(" %d", i);
            printf(" }\n");
        }
    }
};
/*
Kusaraji ksrj;
ksrj.readGraph();
ksrj.solve();
*/


int main() {
    Kusaraji ksrj;
    ksrj.readGraph();
    ksrj.solve();
}