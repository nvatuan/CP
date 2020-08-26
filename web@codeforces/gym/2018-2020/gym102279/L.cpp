#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, L, R, C, x, y;
    cin >> N >> L >> R >> C;
    cin >> x >> y;
    x--, y--;
    // --
    vector< vector<pair<int, long long>> > edgeList( N, vector<pair<int, long long>>() );
    for(int i = 0; i < N; i++) {
        if(i < N-1) edgeList[i].push_back({i+1, R});
        if(i > 0)   edgeList[i].push_back({i-1, L});
    }

    vector<int> Color (N, 0);
    unordered_map<int, int> label;
    int labelCount = 1;
    //
    for(int i = 0; i < N; i++) {
        scanf("%d", &Color[i]);
        if(!label[Color[i]]) label[Color[i]] = labelCount++;
        Color[i] = label[Color[i]];
    }
    //
    for(int i = 0; i < labelCount; i++) edgeList.push_back( vector<pair<int, long long>>() );
    for(int i = 0; i < N; i++) {
        edgeList[i].push_back( {N + Color[i] - 1, C} );
        edgeList[N + Color[i] - 1].push_back( {i, 0} );
    }

    // --
    vector<long long> cost (N + labelCount, LLONG_MAX);
    cost[x] = 0;
    
    vector<int> V (N + labelCount, 0);

    priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > PQ;
    PQ.push( {cost[x], x} );

    // -- Dijsktra;
    while( !PQ.empty() ) {
        long long curCost   = PQ.top().first;
        int node            = PQ.top().second; 
        PQ.pop();
        // --
        if(node == y) {
            cout << curCost;
            return 0;
        }
        if(V[node]) continue;
        V[node] = 1;
        //
        for(auto &v : edgeList[node]) {
            int         nextNode        = v.first;
            long long   nextNodeCost    = v.second;
            if(!V[nextNode] && cost[nextNode] > curCost + nextNodeCost ) {
                cost[nextNode] = curCost + nextNodeCost;
                PQ.push( {cost[nextNode], nextNode} );
            }
        }
    }
}