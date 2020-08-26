#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

string Next() { string x;   cin >> x; return x; }
llong NextLong() { llong x; cin >> x; return x; }
int NextInt() { int x;      cin >> x; return x; }

void dfs(vector< vector<int> >& edgeList, int node, vector<int>& visited, vector<int>& leaves) {
    if ( visited[node] ) return;
    visited[node] = true;
    //
    bool leafFlag = true;
    for (int nextnode : edgeList[node]) {
        if (!visited[nextnode]) {
            leafFlag = false;
            dfs(edgeList, nextnode, visited, leaves);
        }
    }
    //
    if (leafFlag) {
        leaves.push_back(node);
    }
}

void findLeaves(vector< vector<int> >& edgeList, vector< int >& leaves, int& n) {
    vector<int> visited (n, 0);
    dfs(edgeList, 0, visited, leaves);
}

//
class leaf_pq {
public:
    int idx;
    int dist;
    int stacks = 1;
    int is_leaf = 0;
    //
    leaf_pq(int i, int d, int l = 0) : idx(i), dist(d), is_leaf(l) {
    }
    bool operator<(const leaf_pq leaf) const {
        return this->dist < leaf.dist; 
    }
};

void solve() {
    int n = NextInt(); int k = NextInt();
    vector< vector<int> > edgeList (n, vector<int>() );
    for (int a, b, i = 1; i < n; i++) {
        cin >> a >> b;
        a--, b--;
        edgeList[a].push_back(b);
        edgeList[b].push_back(a);
    }
    // -- calculate dist
    vector<int> distanceToRoot (n, 0);
    { // bfs
        queue< pair<int, int> > Q;
        vector<int> vis (n, 0);
        //
        Q.push( {0, 0} );
        while (!Q.empty()) {
            int node = Q.front().first;
            int dist = Q.front().second;
            Q.pop();
            if (vis[node]) continue;
            vis[node] = true;
            distanceToRoot[node] = dist;
            //
            for (int nextnode : edgeList[node]) Q.push({nextnode, dist+1});
        }
        //
    }
    // -- find leaves
    vector<int> leaves;
    findLeaves(edgeList, leaves, n);
    // -- ??
    vector<int> vis (n, 0);
    vector<int> stacks (n, 0);
    
    priority_queue<leaf_pq, vector<leaf_pq>> PQ;
    priority_queue<leaf_pq, vector<leaf_pq>> PQ_LEAF;

    vector<int> isLeaf (n, 0);
    for (int &leaf : leaves) {
        PQ_LEAF.push(leaf_pq(leaf, distanceToRoot[leaf], 1));
        isLeaf[leaf] = true;
    }

    while ( k > 0 ) {
        if (PQ.empty()) {
            leaf_pq lpq = PQ_LEAF.top();
            PQ_LEAF.pop();
            //
            PQ.push(lpq);
            // --
            assert( stacks[lpq.idx] == 0);
            stacks[lpq.idx]++;
        } else {
            leaf_pq tpq = PQ.top();
            if (tpq.dist == PQ_LEAF.top().dist) {
                tpq = PQ_LEAF.top();
                // 
                PQ.push(PQ_LEAF.top());
                PQ_LEAF.pop();
                // --
                assert( stacks[tpq.idx] == 0);
                stacks[tpq.idx]++;                
            } else {
                PQ.pop();
                bool skipFlag = false;
                //
                for (int &nextnode : edgeList[tpq.idx]) {
                    if ( distanceToRoot[nextnode] < tpq.dist ) {
                        if (distanceToRoot[nextnode] >= PQ_LEAF.top().dist) {
                            PQ.push(PQ_LEAF.top());
                            stacks[PQ_LEAF.top().idx];
                            PQ_LEAF.pop();
                            break;
                        } else {
                            if (vis[nextnode]) {
                                skipFlag = true;
                                stacks[nextnode] += stacks[tpq.idx];
                                stacks[tpq.idx] = 0;
                                // skip k--;
                            } else {
                                vis[nextnode] = true;
                                stacks[nextnode] = stacks[tpq.idx] + 1;
                                stacks[tpq.idx] = 0;
                            }
                        }
                    }
                }
                //
                if (skipFlag) continue;
            }
        }
        // --
        k--;
    }
    //
    llong ans = 0;
    cout << "PRINT STACKS:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " " << stacks[i] << endl;
    }

    for (int i = 1; i < n; i++) ans += 1LL*(distanceToRoot[i])*stacks[i];
    cout << ans << '\n';
}

int main() {
    for (int t = NextInt(); t; t--) solve();
}