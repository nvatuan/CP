#include <bits/stdc++.h>
using namespace std;

int b, g, n;
int ans = 0;

int main () {
    cin >> b >> g >> n;
    for(int ib = 0; ib <= b; ib++) {
        for(int ig = 0; ig <= g; ig++) {
            ans += (ib + ig == n);
        }
    }
    cout << ans;
}