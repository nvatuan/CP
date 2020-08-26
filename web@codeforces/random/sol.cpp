#include <bits/stdc++.h>
using namespace std;

long long n;
long long ans = 0;
long long l, r;
vector<long long> a;

long long countBit(long long x) {
    long long bits = 0;
    while (x > 0) { bits++; x >>= 1LL; }
    return bits;
}

long long leng(long long x) {
    return ((1LL << countBit(x)) - 1LL);
}

long long cal(long long prefix, long long val) {
    if (prefix < 0) return 0LL;

    long long bitCount = countBit(val);
    long long result = 0;
    long long x, d;
    for (long long bit = 0; bit < bitCount; bit++) { // 50
        x = (1LL << bit) - 1LL;
        d = (1LL << (bit + 1));
        long long b = (!!(val & (1LL << (bitCount - bit - 1))));
        // while (x <= prefix) {
        //     result += b;// (!!(val & (1LL << bit)));
        //     x += d;
        // }
        if (prefix >= x) 
            if (b) result += (prefix - x)/d + 1;
    }
    return result;
}

long long cal(long long L, long long R, long long val) {
    // printf("@cal: L = %lld, R = %lld\n", L, R);
    return cal(R - 1, val) - cal(L-2, val);
}

void solve() {
    cin >> n;
    cin >> l >> r;
    //a.resize(n, 0LL);
    //for (long long& i : a) cin >> i;
    a.resize(1, n);
    
    int i = 0;
    long long j = 0;
    long long LeftEnd = -1, RightEnd = -1;
    for (; i < 1 and 0 < r; ) {
        long long expansionLength = leng(a[i]);
        if (expansionLength < l) { // [l, r]
            l -= expansionLength;
            r -= expansionLength;
        } else {
            if (LeftEnd == -1) LeftEnd = l;
            else LeftEnd = 0;
            
            RightEnd = expansionLength;
            if (r < RightEnd) RightEnd = r;

            ans += cal(LeftEnd, RightEnd, a[i]);

            l -= expansionLength;
            r -= expansionLength;
        }
        i++;
    }
    cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}
