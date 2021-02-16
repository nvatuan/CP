#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e3; // good enough, gives dp larger than 5000
int np[N];
vector<int> primes;
void sieve() {
    np[0] = np[1] = 1;
    for (int i=2; i<N; i++)
        if (!np[i]) {
            primes.push_back(i);
            for (long long j = 1LL*i*i; j < N; j += i) np[j] = 1;
        }
}

long long dp[N][N];
void calculate() {
    for (int j=0; j<N; j++) dp[0][j] = 1;
    for (int i=1; i<N; i++) {
        for (int j=1; j < N; j++) {
            dp[i][j] = dp[i][j-1];
            if (np[j]) continue;
            if (j <= i) dp[i][j] += dp[i-j][j];
        }
    }
}

int main() {
    sieve();
    calculate();
    int n; cin >> n;
    int ans = 1;
    for (ans = 1; dp[ans][ans] < n; ans++);
    cout << ans << '\n';
}