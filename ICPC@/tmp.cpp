#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int check(int l) {
    for (int i=0; i+l<n; i++) {
        int chr = 'A';
        for (int j=0; j<l; j++) {
            if (chr == s[i+j]) {
                if (chr == 'Z') return 1;
                else chr++;
            }
        }
    }
    return 0;
}

void solve() {
    cin >> n >> s;

    int l = 29, r = n;
    while (l < r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << r << endl;
}

int main() {
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}
