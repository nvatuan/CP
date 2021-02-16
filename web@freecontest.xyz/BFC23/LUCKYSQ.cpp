#include <bits/stdc++.h>
using namespace std;

int n, x;
long long p[int(1e6) + 10];
long long sum_subarr_table[int(1e6) + 10];

const int N = int(1e6) + 10;

void reset_table() {
    fill(sum_subarr_table, sum_subarr_table+N, 0);
}
void inc_table(long long x) {
    if (x >= N or x < 0) return;
    sum_subarr_table[x]++;
}
long long get_table(long long x) {
    if (x >= N or x < 0) return 0;
    return sum_subarr_table[x];
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> x;
    for (int i=1; i<=n; i++) cin >> p[i];

    for (int i=1; i<=n; i++) p[i] += p[i-1];

    long long ans = 0;
    for (long long d=1; d*d <= x; d++) {
        if (x % d == 0) {
            long long sum_reduce = x/d;
            reset_table();

            for (int i=d; i<=n; i++) {
                long long sum_subarr = p[i] - p[i-d];
                inc_table(sum_subarr);
            }

            for (int i=d; i<=n; i++) {
                long long sum_subarr = p[i] - p[i-d];
                ans += get_table(sum_reduce - sum_subarr);
            }
        }
    }
    cout << ans << '\n';
}