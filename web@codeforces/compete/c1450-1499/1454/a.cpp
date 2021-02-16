#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    std::iota(a.begin(), a.end(), 1);
    std::rotate(a.begin(), a.begin() + 1, a.end());
    for (int i : a) cout << i << ' ';
    cout << endl;
}

int main() {
    int t;
    for (cin >> t; t; t--)
        solve();
}