#include <bits/stdc++.h>
using namespace std; 

void solve() {
    map<int, int> cnt;
    int n; cin >> n;
    for (int i = 0; i<n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int mexA = 0, mexB = 0;
    while (cnt[mexA] >= 1) mexA++;
    while (cnt[mexB] >= 2) mexB++;
    cout << mexA + mexB << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}