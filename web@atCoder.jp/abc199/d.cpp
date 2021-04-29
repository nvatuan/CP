#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

long long ans=1;
long long comp_ans[25];

int color[100];

vector<vector<int>> component;
int visited[25] = {};

void discover(int vertex, int cid=-1) {
    if (cid==-1) {
        cid = component.size();
        component.push_back(vector<int>(0));
    }

    visited[vertex] = true;
    component[cid].push_back(vertex);
    for (int nxt : adj[vertex]) {
        if (not visited[nxt]) {
            discover(nxt, cid);
        }
    }
}

void tryColor(int vid, const int& cid) {
    if (vid >= component[cid].size()) {
        comp_ans[cid]++;
        // for (int i=0; i<n; i++) cout << color[i] << ' ';
        return;
    }

    int vertex = component[cid][vid];
    for (int cl=1; cl<4; cl++) {
        int flag = 1;

        for (int neighbor : adj[vertex]) {
            if (color[neighbor]==cl) flag = 0;
        }

        if (flag) {
            color[vertex] = cl;
            tryColor(vid+1, cid);
            color[vertex] = 0;
        }
    }
}



int main() {
    cin >> n >> m;
    adj.resize(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i=0; i<n; i++) {
        if (visited[i] == 0) discover(i);
    }

    
    for (int cid=0; cid<component.size(); cid++) {
        tryColor(0, cid);
        ans *= comp_ans[cid];
    }

    cout << ans << endl;
}

