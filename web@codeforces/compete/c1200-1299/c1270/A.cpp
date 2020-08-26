#include <bits/stdc++.h>
using namespace std;

int t;
int n, k1, k2;
int mx1, mx2;
int tmp;

int main() {
    for(cin >> t; t; t--) {
        cin >> n >> k1 >> k2;
        mx1 = mx2 = 0;
        //
        while(k1--) {
            cin >> tmp;
            mx1 = max(mx1, tmp);
        }
        //
        while(k2--) {
            cin >> tmp;
            mx2 = max(mx2, tmp);
        }
        //
        cout << (mx1 > mx2 ? "YES\n" : "NO\n");
    }
    return 0;
}