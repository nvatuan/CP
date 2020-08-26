#include <bits/stdc++.h>
using namespace std;

int m, n;

int main() {
    for(cin >> m; m; m--) {
        cin >> n;
        //
        long long ans = 0;
        vector<long long> h (n, 0);
        for(int i = 0; i < n; i++) scanf("%lld", &h[i]);
        sort(h.begin(), h.end());
        //
        long long stop = -11;
        for(auto &x : h) {
            if( x > (stop+10) ) {
                ans++;
                stop = x+10;
            }
        }
        //
        printf("%lld\n", ans);
    }
}