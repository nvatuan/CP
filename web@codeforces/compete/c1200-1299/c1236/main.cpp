#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c;
    for(cin >> t; t; t--) {
        int ans = 0;
        cin >> a >> b >> c;
        while(b > 0 && c > 1) {
            ans += 3;
            c -= 2;
            b -= 1;
        }
        while(a > 0 && b > 1) {
            ans += 3;
            b -= 2;
            a -= 1;
        }
        cout << ans << '\n';
    }
}