#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;

    vector<int> p[2];
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        p[x % 2].push_back(x);
    }
    for (int i:p[0]) cout << i << ' ';
    for (int i:p[1]) cout << i << ' ';
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}