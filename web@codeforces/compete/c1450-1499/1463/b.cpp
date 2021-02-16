#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];
int b[100];

void solve() { 
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int idx = (int)(min_element(a, a + n) - a);
    b[idx] = a[idx];
    for (int i=idx-1; i >= 0; i--) {
        b[i] = b[i+1];
        while (a[i] > b[i]*2) {
            b[i] <<= 1;
        }
        while (a[i] < b[i]) {
            assert(b[i] % 2 == 0);
            b[i] >>= 1;
        }
    }
    for (int i=idx+1; i < n; i++) {
        b[i] = b[i-1];
        while (a[i] > b[i]*2) {
            b[i] <<= 1;
        }
        while (a[i] < b[i]) {
            assert(b[i] % 2 == 0);
            b[i] >>= 1;
        }
    }

    int total=0;
    for (int i=0; i<n; i++) {
        total += abs(a[i] - b[i]);
        cout << b[i] << ' ';
    }
    cout << endl;

    //int sum=0;
    //for (int i =0; i<n; i++) sum += a[i];
    //cout << total*2 << '<' << sum << '\n';
    //cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}