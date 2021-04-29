#include <bits/stdc++.h>
using namespace std;

int N, W;
int w[105], v[105];

const int DP_SIZE=(int)(1e5+10);
long long dp[DP_SIZE];
// dp[k][v] Trong luong it nhat, khi xet den k-th item va co gia tri la v

int main() {
    cin >> N >> W;
    for (int i=0; i<N; i++) {
        cin >> w[i] >> v[i];
    }

    const long long INF = (long long)(1e14);
    fill (dp, dp+DP_SIZE, INF);
    dp[0] = 0LL;

    for (int i=0; i<N; i++) {
        for (int value=DP_SIZE-1; value >= v[i]; value--)
            if (dp[value-v[i]] != INF) {
                dp[value] = min(dp[value-v[i]] + w[i], dp[value]);
            }
    }

    for (int value=DP_SIZE-1; value >= 0; value--) {
        if (dp[value] <= W) {
            printf("%d\n", value);
            return 0;
        }
    }
}