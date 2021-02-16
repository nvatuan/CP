#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> t (n);
    for (int &i : t) cin >> i;
    sort(t.begin(), t.end());

    int LAST = 2*n + 15;
    int INF = (int)(1e9);
    vector<vector<int>> dp (n+1, vector<int>(LAST, INF));

    for (int T=1; T < LAST; T++) dp[0][T] = abs(T - t[0]);

    for (int dish=1; dish<n; dish++) {
        for (int T=dish+1; T < LAST; T++) {
            int min_unplesant = *min_element(dp[dish-1].begin(), dp[dish-1].begin() + T);
            dp[dish][T] = abs(T - t[dish]) + min_unplesant;
        }
    }
    // for (int dish=0; dish<n; dish++) {
    //     for (int T=1; T < LAST; T++) {
    //         if (dp[dish][T] >= INF) cout << "INF";
    //         else cout << dp[dish][T];
    //         cout << ' ';
    //     }
    //     cout << endl;
    // }

    cout << *min_element(dp[n-1].begin() + n, dp[n-1].end()) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}