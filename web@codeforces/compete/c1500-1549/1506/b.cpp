#include <bits/stdc++.h>
using namespace std;

int n, k;
string st;

void solve() {
    cin >> n >> k;
    cin >> st;

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (st[i] == '*') {
            st[i] = 'x';
            ans++;
            break;
        }
    }
    for (int i=n-1; i>=0; i--) {
        if (st[i] == '*') {
            st[i] = 'x';
            ans++;
            break;
        }
    }

    int start = st.find('x');
    if (start == string::npos) {
        cout << 0 << '\n';
        return;
    }

    int last = st.find_last_of('x');

    for (int i=start; i<last;) {
        for (int j=min(i+k, n-1); j>i; j--) {
            if (st[j] == '*') {
                st[j] = 'x';
                ans++;
            }
            if (st[j] == 'x') {
                i=j;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}