#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a (n);

    int l = 0, r = n-1;
    int v = 1;
    for (int i = 0; i < n; i++) {
        if (i & 1) a[r--] = v++;
        else a[l++] = v++;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}