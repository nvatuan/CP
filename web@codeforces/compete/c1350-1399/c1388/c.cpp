#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100001];
int h[100001];

vector<vector<int>> edge;

int visited[100001];
void dfs(int x) {
    visited[x] = 1;
    for (int& node : edge[x])
        if (not visited[node]) {
            //printf("@dfs %d -> %d\n", x, node);
            dfs(node);
            p[x] += p[node];
        }
}

int Good[100001], Bad[100001];
int calculateExactHappy() {
    for (int x = 0; x < n; x++) {
        int good, bad;
        
        good = (p[x] + h[x])/2;
        bad = p[x] - good;
        
        Good[x] = good; Bad[x] = bad;

        // printf("%d | Good = %d | Bad = %d \n", x, Good[x], Bad[x]);
        // printf("People = %d\n", p[x]);
        
        if (Good[x] * Bad[x] < 0) return false;
        if (Good[x] - Bad[x] != h[x]) return false;
    }   
    
    return true;
}

int waterfall(int x) {
    visited[x] = 1;

    int childGood = 0;
    for (int& node : edge[x])
        if (not visited[node])
            childGood += Good[node];

    if (childGood <= Good[x]) {
        bool flag = true;
        for (int& node : edge[x])
            if (not visited[node])
                flag &= waterfall(node);
        if (flag) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);

    edge = vector<vector<int>> (n, vector<int>());
    for (int a, b, i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    // -- solve
    fill(visited, visited+n, 0);
    dfs(0);
    if (not calculateExactHappy()) {
        printf("NO\n");
        return;
    }

    // for (int i = 0; i < n; i++) printf("%d ", p[i]);
    // printf("\n");

    fill(visited, visited+n, 0);
    if (waterfall(0)) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}