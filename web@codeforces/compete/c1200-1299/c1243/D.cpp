#include <bits/stdc++.h>
using namespace std;

int n, m;

struct PairHash {
    template <class T1, class T2>
    long long operator()(const pair<T1, T2> &pair) const {
        return (long long)(pair.first)*100007 + (long long)(pair.second);
    }
};

unordered_map<pair<int, int>, int, PairHash> no;

vector<int> vis;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = 1;
    for(int i = 0; i < n; i++) {
        if( !no[{i, x}] ) dfs(i);
    }
}


vector<int> Size(100001, 1);
vector<int> Root(100001, -1);

int get_root(int x) {
    while(x != Root[x]) x = Root[x];
    return x;
}

void unite(int a, int b) {
    int r_a = get_root(a);
    int r_b = get_root(b);
    if(Size[r_a] < Size[r_b]) {
        Root[r_b] = r_a;
        Size[r_a] += Size[r_b];
    } else {
        Root[r_a] = r_b;
        Size[r_b] += Size[r_a];
    }
}

int main(){
    for(int i = 0; i < 100001; i++) {
        Root[i] = i;
    }
    scanf("%d%d", &n, &m);
    for(int a, b, i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        unite(a, b);
    }
    // --
    unordered_set<int> S;
    for(int i = 0; i < n; i++) {
        int R = get_root(i);
        S.insert(R);
    }
    // --
    cout << S.size() - 1;
} 