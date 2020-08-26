#include <bits/stdc++.h>
using namespace std;

int B[1005][1005];
long long dp[1005][1005][3];

int M, N;
char c;

long long min(long long a, long long b, long long c) {
    return min(min(a, b), c);
}

long long max(long long a, long long b, long long c) {
    return max(max(a, b), c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> c;
            B[i][j] = (c == 'G');
        }
    }
    // --
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            for(int b = 0; b < 2; b++) {
                for(int bb = 0; bb < 2; bb++) {
                    if(B[i][j] ^ b) {
                        dp[i][j][b] = max( dp[i][j][b], min(dp[i-1][j][bb], dp[i-1][j-1][bb], dp[i][j-1][b]) + 1);
                    }    
                }   
            }
        }
    }
    // --
    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            ans = max(ans, dp[i][j][0], dp[i][j][1]);
        }
    }
    //
    cout << ans*ans;
}