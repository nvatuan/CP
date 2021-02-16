#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    int child = 0;
    int inc_seq_allowed = 1;
    int next_inc_seq_allowed = 0;

    int height = 2;
    for (int i=1; i<n; i++) {
        if (a[i-1] < a[i]) {
            child++;
        } else {
            next_inc_seq_allowed += child;
            child = 1;
            
            inc_seq_allowed--;
            if (inc_seq_allowed == 0) {
                inc_seq_allowed = next_inc_seq_allowed;
                next_inc_seq_allowed = 0;
                height++;
            }
        }
    }

    cout << height - 1 << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}