#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> a (n);
    for (int&i : a) cin >> i;

    int root = distance(max_element(a.begin(), a.end()), a.begin());
    unordered_map<int, int> left, right;

    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(root, 0, n-1));
    while (not Q.empty()) {
        auto tup = Q.front(); Q.pop();
        int idx = get<0>(tup);
        int Lx = get<1>(tup);
        int Rx = get<2>(tup);

        int l = distance(max_element(a.begin() + Lx, a.begin() + idx), a.begin());
        int r = distance(max_element(a.begin() + idx + 1, a.end()), a.begin());
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}