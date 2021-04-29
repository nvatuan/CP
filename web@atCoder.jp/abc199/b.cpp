#include <bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int b[10000];

int main() {
    cin >> n;
    int l=0, r=1001;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) {
        l = max(l, a[i]);
        r = min(r, b[i]);
    }
    if (l <= r) {
        cout << r-l+1 << endl;
    } else {
        cout << 0 << endl;
    }
}
