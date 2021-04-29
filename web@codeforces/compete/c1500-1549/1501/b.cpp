#include <bits/stdc++.h>
using namespace std;

int n;
int a[(int)(2e5)+100];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    vector<int> m(n, 0);

    int ptr=n-1;
    for (int i=n-1; i>=0; i--) {
        if (ptr > i) ptr = i;
        while (ptr > max(-1, i-a[i])) {
            m[ptr]=1;
            ptr--;
        }
    }

    for (int i:m) printf("%d ", i);
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}