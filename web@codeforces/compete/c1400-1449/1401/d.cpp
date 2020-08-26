#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

const llong M = (llong(1e9)) + 7;
llong n, k, m;

vector<vector<int>> tree;
vector<llong> factor;

void input();

int root = 0;
void get_root() {
    root = 0;
    int parent = -1;
    while (true) {
        bool breakFlag = true;
        for (int & child : tree[root]) 
            if (child != parent) {
                parent = root;
                root = child;
                breakFlag = false;
                break;
            }
        if (breakFlag) break;
    }
    return;
}

llong dp[100005];
llong cal_subtree(int x, int p = -1) {
    if (dp[x] > -1) return dp[x];

    llong subtree = 1;
    for (int& child : tree[x]) {
        if (child != p)
            subtree += cal_subtree(child, x);
        assert(subtree > 0);
    }

    dp[x] = subtree;
    return dp[x];
}

void solve() {
    input();
    // -- compact factor list;
    sort(factor.begin(), factor.end());
    while (m > n-1) {
        llong mul = factor.back();
        factor.pop_back();
        factor.back() = (factor.back() * mul) % M;
        m--;
    }
    reverse(factor.begin(), factor.end());
    while(factor.size() < n-1) factor.push_back(1);

    cerr << "Compacted factorlist\n";
    // -- get root
    get_root();
    cerr << "Root gotten\n";

    fill(dp, dp + n, -1LL);
    cal_subtree(root);
    cerr << "DP subtree calculated\n";


    vector<llong> edgeSorted;
    for (int i = 0; i < n; i++)
        if (i != root) edgeSorted.push_back(dp[i]);
    sort(edgeSorted.begin(), edgeSorted.end(), greater<llong>());

    llong ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans += ((edgeSorted[i] % M) * (factor[i] % M) % M);
    }
    
    cerr << "DEBUG edgeSorted\n";
    for (int i = 0; i < n-1; i++) {
       cerr << edgeSorted[i] << ' ';
    }
    cerr << "\nDEBUG factor\n";
    for (int i = 0; i < n-1; i++) {
        cerr << factor[i] << ' ';
    }
    cerr << '\n';

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}

void input() {
    cin >> n;
    tree.clear();
    tree.resize(n, vector<int>());
    for (int a, b, i = 0; i < n-1; i++) {
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    
    cin >> m;
    factor.resize(m);
    for (llong& ll : factor) cin >> ll;
    cerr << "input done\n";
}