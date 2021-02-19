#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

vector<llong> cube;

const llong INF = (llong)(1e12 + 5);

void init() {
    for (llong a=1; a*a*a < INF; a++) {
        cube.push_back(a*a*a);
    }
}

void solve() {
    llong x;
    cin >> x;

    for (llong a : cube) {
        if (binary_search(cube.begin(), cube.end(), x-a)) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}

int main() {
    init();

    int t; cin >> t;
    while (t--)
        solve();
}