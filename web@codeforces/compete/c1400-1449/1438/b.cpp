#include <bits/stdc++.h>
using namespace std;

int n;
int a[20001];

void solve() {
    cin >> n;
    map<int, int> chec;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        chec[a[i]]++;
    }
    for (int i=0; i<n; i++) {
        if (chec[a[i]] > 1) {
            cout << "YES\n"; return;
        }
    }
    cout <<"NO\n";
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}