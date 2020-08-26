#include <bits/stdc++.h>
using namespace std;

#define M (int(1e9) + 7)
long long dp[505][105];

int N, X;
int L[105];

int main() {
    cin >> N >> X;
    for(int i = 1; i <= N; i++) {
        cin >> L[i];
    }
    // --
    sort(L, L + N + 1);
    //
    for(int x = 0; i < X; i++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) continue;
                if(x < L[i]) break;
                dp[x][i] = (dp[x][i] + dp[x - L[i]][]
            }
        }
    }
}