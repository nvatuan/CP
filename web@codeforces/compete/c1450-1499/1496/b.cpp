#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[(int)(2e5)];

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];

    if (k == 0) {
        cout << n << endl;
        return;
    }

    sort(a, a+n);

    int incr=(a[0] == 0);
    for (int i=1; i<n; i++) {
        incr &= (a[i-1] + 1 == a[i]);
    }
    if (incr) { // mex > max
        printf("%d\n", n+k);
    } else {
        map<int, int> mark;
        for (int i=0; i<n; i++) mark[a[i]]=1;

        int mex=0;
        while (mark[mex]) mex++;

        int mx = a[n-1];
        if (mark[(mex + mx + 1)/2]) {
            printf("%d\n", n);
        } else {
            printf("%d\n", n+1);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}