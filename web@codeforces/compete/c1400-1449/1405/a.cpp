#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int&i : p) cin >> i;
    reverse(p.begin(), p.end());
    for (int i : p) cout << i << ' ';
    cout << endl;
}

int main() {
    int t; cin>>t;
    while(t--)
        solve();
}