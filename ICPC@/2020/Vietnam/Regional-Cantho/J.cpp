#include <bits/stdc++.h>
using namespace std;

long long bound = 3e18;
vector<long long> p;

long long n, m;

int check(long long x) {
    long long ans = 0;
    long long tmp = n;
    for (long long ll : p) {
        fprintf(stderr, "> LL = %lld | Tmp = %lld\n", ll, tmp);
        if (tmp == 0) break;

        long long maxDec, maxInc;
        if (tmp >= (ll*2-1)) {
            maxDec = ll, maxInc = ll*3-2; 
            tmp -= (ll*2-1);
        } else {
            maxDec = ll - (tmp+1)/2 + 1, maxInc = ll*2 + (tmp-1)/2;
            tmp = 0;
        }
        if (ll == 1) {
            ans += max(0LL, min(maxDec, x));
        } else {
            if (maxInc >= x) ans += x;
            else ans += ll;
            if (maxDec <= x) ans += (x - maxDec + 1);
        }
        fprintf(stderr, "Ans = %lld\n", ans);
    }
    fprintf(stderr, "Answer = %lld\n", ans);
    return (x >= m);
}

void solve() {
    cin >> n >> m;
    
    long long L = 1, R = LLONG_MAX;
    while (L + 1 < R) {
        long long mid = L + (R - L)/2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << R << '\n';
}

int main() {
    for (long long x = 1; x < bound; x = x*3 - 1) p.push_back(x);

    /*int t; cin >> t;
    while (t--)
        solve();
        */
    n = 6;
    while (true) {
        cin >> m;
        cout << check(m) << endl;
    }
}