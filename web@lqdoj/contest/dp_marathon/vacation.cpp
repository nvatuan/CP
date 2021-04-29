#include <bits/stdc++.h>
using namespace std;

int N;
int a[(int)(1e5)+10];
int b[(int)(1e5)+10];
int c[(int)(1e5)+10];

long long dp[2][3];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    dp[1][0] = dp[1][1] = dp[1][2] = 0LL;
    int flip = 0;

    for (int i=0; i<N; i++) {
        int h[3] = {a[i], b[i], c[i]};

        for (int actPrev=0; actPrev<3; actPrev++)
            for (int act=0; act<3; act++)
                if (actPrev != act) {
                    dp[flip][act] = max(dp[flip][act], dp[flip^1][actPrev] + h[act]);
                }

        flip ^= 1;
    }
    printf("%lld\n", *max_element(dp[flip^1], dp[flip^1]+3));
}