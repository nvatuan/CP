#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];

void solve() {
    cin >> n;

    map<int, int> occ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        occ[a[i]]++;
    }

    int maxOcc = 0;
    int maxInd = 0;
    for (int i = 0; i < n; i++) {
        if (occ[a[i]] > maxOcc) {
            maxInd = i;
        }
    }

    vector<vector<int>> dp (maxOcc + 5,, vector<int> (occ.size(), 0));
    dp[0][0] = 1;
    int incr = 1;
    for (auto p : occ) {
        for (int w = maxOcc; w >= p.second; w--)
            dp[w][incr] = dp[w-p.second][incr]
        incr++;
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}