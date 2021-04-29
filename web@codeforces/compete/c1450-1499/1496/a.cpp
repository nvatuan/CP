#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;

    if (k*2 >= n) {
        cout << "NO\n";
        return;
    }

    int good=1;
    int l=0, r=n-1;
    while (k-- > 0) {
        if (s[l] != s[r]) good=0;
        l++;
        r--;
    }
    cout << (good ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}