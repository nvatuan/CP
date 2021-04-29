#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int &i : a) cin >> i;

    int m=-1, c=-1;

    int is_gradual=1;
    for (int i=2; i<n; i++) {
        is_gradual &= (a[i] - a[i-1] == a[i-1] - a[i-2]);
    }

    if (is_gradual) {
        cout << 0 << endl;
        return;
    }

    for (int i=1; i<n; i++) {
        if (a[i-1] < a[i]) {
            c = a[i] - a[i-1];
            break;
        }
    }
    for (int i=1; i<n; i++) {
        if (a[i-1] > a[i]) {
            m = a[i-1] + c - a[i];
            break;
        }
    }

    int poss = (c < m) && (a[0] < m);
    for (int i=1; i<n; i++) {
        poss &= (a[i] == ((a[i-1]+c)%m));
    }
    if (poss) {
        cout << m << ' ' << c << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}