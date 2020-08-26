#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string ans (n, '9');
    int eight = n/4 + (n % 4 >= 1);
    for (int i = n-1; eight; eight--, i--) ans[i] = '8';
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}