#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000];
long long x;

int main() {
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> a[i];

    long long ans = LLONG_MAX;
    for (int k=1; k<=100; k++) {
        vector<vector<int>> dp (k+1, vector<int> (k, -1));
        dp[0][0] = 0;

        for (int i=0; i<n; i++) {
            for (int c=k-1; c>=0; c--) {
                for (int r=0; r<k; r++) {
                    if (dp[c][r] == -1) continue;
                    int nxt = dp[c][r] + a[i];
                    dp[c+1][(r+a[i]) % k] = max (
                        dp[c+1][(r+a[i]) % k], nxt
                    );
                }
            }
        }
        if (dp[k][(x % k)] == -1) continue;
        ans = min(ans, (x - dp[k][(x % k)])/k);
    }
    cout << ans << endl;
}