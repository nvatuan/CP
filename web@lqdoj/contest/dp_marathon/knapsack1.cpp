#include <bits/stdc++.h>
using namespace std;

int N, W;
int w[105], v[105];

long long dp[100005];

int main() {
    scanf("%d%d", &N, &W);
    for (int i=1; i<=N; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }

    fill(dp, dp + W + 3, -1);
    dp[0] = 0LL;

    for (int item=1; item<=N; item++) {
        // for (int wi=0; wi<=W; wi++) cout << dp[wi] << ' ';
        // cout << endl;
        for (int weight=W; weight>=w[item]; weight--) {
            if (dp[weight-w[item]] != -1)
                dp[weight] = max(dp[weight], dp[weight-w[item]] + v[item]);
        }
    }
    // for (int wi=0; wi<=W; wi++) cout << dp[wi] << ' ';
    // cout << endl;

    printf("%lld\n", *max_element(dp, dp+W+1));
}