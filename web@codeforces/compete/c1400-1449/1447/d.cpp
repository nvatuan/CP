#include <bits/stdc++.h>
using namespace std;

const int S = 3;

const int N = 5005;
int dp[N][N];

int n, m;

void solve() {
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                int maxSubDP = 0;
                for (int di = 1; di <= 3; di++) 
                    for (int dj = 1; dj <= 3 - di + 1; dj++)
                        maxSubDP = max(maxSubDP, dp[i+S-di][j+S-dj] - (di+dj-2));
                dp[i+S][j+S] = maxSubDP + 4 - 2;
            } else {
                int maxSubDP = 0;
                for (int di = 0; di < 3; di++) 
                    for (int dj = 0; dj < 3 - di + 1; dj++)
                        maxSubDP = max(maxSubDP, dp[i+S-di][j+S-dj] - (di+dj));
                dp[i+S][j+S] = max(0, maxSubDP);
            }
            ans = max(ans, dp[i+S][j+S]);
        }
    }
    // for (int i=S; i < S+n; i++) {
    //     for (int j=S; j < S+m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
}