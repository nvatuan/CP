#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; string s;
    map<char, int> cnt;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c : s) cnt[c]++;
    }

    bool flag = true;
    for (auto p : cnt) {
        flag &= (p.second % n == 0);
        //cout << p.first << ' ' << p.second << endl;
    }
    cout << (flag ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}