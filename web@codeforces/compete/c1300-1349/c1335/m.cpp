#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

string  NextString()    { string x; cin >> x; return x; }
int     NextInt()       { int x;    cin >> x; return x; }
llong   NextLong()      { llong x;  cin >> x; return x; }
char    NextChar()      { char x;   cin >> x; return x; }

// --
int n;
vector<int> a (2001);

void solve() {
    n = NextInt();
    generate(a.begin(), a.begin() + n, NextInt);
    
    // -- DEFINING CHECK --
    {
        int ans = 0;
        for (int x = 1; x <= n/2; x++) {
            int y = 0;
            assert(y >= 0);
            
            int L = 0, R = n-1;
            //
            map<int, int> M1, M2, M3;
            bool flag;
            // -- 1st Block
            for (int mxCount = -1; L < n; L++) {
                M1[a[L]]++;
                mxCount = max(mxCount, M1[a[L]]);
                if (mxCount >= x) {
                    flag = true;
                    break;
                }
            }
            if (!flag) continue;
            if (L + x >= n) continue;

            // -- 3rd Block
            for (int mxCount = -1; L < R; R--) {
                M2[a[R]]++;
                mxCount = max(mxCount, M2[a[R]]);
                if (mxCount >= x) {
                    flag = true;
                    break;
                }
            }
            if (!flag) continue;

            // -- succeed
            for (int i = L+1, mxCount = -1; i < R; i++) {
                M3[a[i]]++;
                mxCount = max(mxCount, M3[a[i]]);
                y = max(y, mxCount);
            }
            //
            ans = max(ans, x*2 + y);
        }
        cout << ans << '\n';
    };
}
// --

int main() {
    ios::sync_with_stdio(0);
    //
    for (int t = NextInt(); t; t--) solve();
}