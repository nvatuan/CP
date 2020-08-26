#include <bits/stdc++.h>
using namespace std;

int H, W;
int wall[1002][1002];

int MOD = int(1e9) + 7;
long long dp[1002][1002];

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            wall[i][j] = (c == '#' ? 1 : 0);
        }
    // --
    dp[0][0] = 1;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (wall[i][j]) continue;
            dp[i][j] %= MOD;
            dp[i+1][j] += dp[i][j];
            dp[i][j+1] += dp[i][j];
        }
    //
    cout << dp[H-1][W-1] << endl;
}