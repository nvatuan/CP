#include <stdio.h>
#include <math.h>

int n, K;
int H[100001];
long long DP[100001];

long long max(long long a, long long b) {
    return (a > b ? a : b);
}
long long min(long long a, long long b) {
    return (a < b ? a : b);
}

int main() {
    scanf("%d%d", &n, &K);
    for(int i = 0; i < n; i++) scanf("%d", &H[i]);
    
    for(int i = 1; i < n; i++) {
        DP[i] = (long long)(1e16);
        for(int j = max(0, i-K); j < i; j++)
            DP[i] = min( DP[i], DP[j] + abs(H[i] - H[j]));
    }

    printf("%lld", DP[n-1]);
}