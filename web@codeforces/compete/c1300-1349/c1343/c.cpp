#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

int NextInt() { int x; cin >> x; return x; }
char NextChar() { char x; cin >> x; return x; }
string Next() { string x; cin >> x; return x; }
llong NextLong() { llong x; cin >> x; return x; }
double NextDouble() { double x; cin >> x; return x; }

#define __multitest 1
// --

class _dp {
    public:
        llong sumBefore = 0;
        int prevElem = 0;
        int val = 0;
        //
        void p() {
            printf("Sum = %lld\n", sumBefore + prevElem);
            printf("leng = %d\n", val);
        }
        //
        void __reset() {
            sumBefore = 0;
            prevElem = 0;
            val = 0;
        }
};

_dp max(_dp t, _dp d) {
    if (t.val != d.val)
        return (t.val < d.val ? d : t);
    else
        return (t.prevElem < d.prevElem ? d : t);
}

#define _MAXN 200002

_dp dp[_MAXN][2];
int a[_MAXN];

void solve() {
    int n = NextInt();
    //
    generate(a, a+n, NextInt);
    //
    for (int i = 0; i < n; i++) {
        dp[i][0].__reset();
        dp[i][1].__reset();
        if ( a[i] > 0 ) {
            dp[i][1].prevElem = a[i];
            dp[i][1].val = 1;
        } else {
            dp[i][0].prevElem = a[i];
            dp[i][0].val = 1;
        }
    }
    //
    
    for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
            // -- update transition
            dp[i][1].val = dp[i-1][0].val + 1;

            dp[i][1].sumBefore = dp[i-1][0].sumBefore + dp[i-1][0].prevElem;

            dp[i][1].prevElem = a[i];
            // -- update current best ans
        }
        if (a[i] < 0) {
            dp[i][0].val = dp[i-1][1].val + 1;

            dp[i][0].sumBefore = dp[i-1][1].sumBefore + dp[i-1][1].prevElem;

            dp[i][0].prevElem = a[i];
            // --
        }

        dp[i][1] = max(dp[i][1], dp[i-1][1]);
        if (a[i] > 0) dp[i][1].prevElem = max(dp[i][1].prevElem, a[i]);
        dp[i][0] = max(dp[i][0], dp[i-1][0]);
        if (a[i] < 0) dp[i][0].prevElem = max(dp[i][0].prevElem, a[i]);
    }
    //
    /*for (int i = 0; i < n; i++) {
        cout << "\n$$" << i << " > DP Neg:\n";
        dp[i][0].p();
        cout << "\n$$" << i << " > DP Pos:\n";
        dp[i][1].p();
    }*/
    _dp ans = max(dp[n-1][0], dp[n-1][1]);
    cout << ans.sumBefore + ans.prevElem << '\n';
}

// --

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    if (__multitest) {
        for (int t = NextInt(); t; t--) solve();
    }
    else solve();
}