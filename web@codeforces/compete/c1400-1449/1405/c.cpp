#include <bits/stdc++.h>
using namespace std;

int n, k;

#define U 1
#define D -1
#define Q 0

int a[300010];
void solve() {
    cin >> n>>k;
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        if (c == '?') a[i] = Q;
        if (c == '1') a[i] = U;
        if (c == '0') a[i] = D;
    }
    // then, check if for element i and element i+k is equal
    for (int i=0, j=k; j<n; i++,j++) {
        //printf("i=%d, j=%d| ai=%d, aj=%d\n", i, j, a[i], a[j]);
        if (a[j] == Q) { //a[j] is question mark
            a[j] = a[i];
        } else {
            if (a[j] == a[i]);
            else
            if (a[i] == Q) {
                int ki = i, kj=j;
                while (0 <= ki) {
                    if (a[ki] != Q and a[ki] != a[kj]) {
                        cout << "NO\n";
                        return;
                    }
                    a[ki] = a[kj];
                    ki -= k;
                    kj -= k;
                }
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    // check for subseg sum if it's not greater than k/2
    int sneg=0, spos=0;
    auto same_sign = [&](int check, int sign) {
        if (check * sign > 0) return 1;
        return 0;
    };
    for (int i=0,j=0; j<n; j++) {
        if(j-i < k) {
            sneg += same_sign(a[j], -1);
            spos += same_sign(a[j], 1);
        } else {
            sneg += same_sign(a[j], -1);
            spos += same_sign(a[j], 1);
            sneg -= same_sign(a[i], -1);
            spos -= same_sign(a[i], 1);
            i++;
        }
        //printf("%d %d | %d\n", i, j, ss);
        if (sneg > k/2 || spos > k/2) {
            cout << "NO\n";
            return;
        }
    }
    //for (int i=0; i<n; i++) cout << a[i] << ' ';
    //cout << endl;
    cout << "YES\n";
}

int main() {
    int t; cin>>t;
    while(t--)
        solve();
}