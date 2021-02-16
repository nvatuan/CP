#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a (n);
    for(int &i : a) cin>>i;

    map<int, int> mark;
    for (int i=0; i<n; i++) {
        mark[a[i]] = (mark[a[i]] ? -1 : (i+1));
    }
    pair<int, int> ans {INT_MAX, -1};
    for (pair<int, int> p : mark) {
        if (p.second != -1) 
            if (ans > p) ans = p;
    }
    cout << ans.second << '\n';
}

int main() {
    int t;
    for (cin >> t; t; t--)
        solve();
}