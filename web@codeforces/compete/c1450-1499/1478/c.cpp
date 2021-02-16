#include <bits/stdc++.h>
using namespace std;

int n;
long long a[(int)(2e5)+100];

void solve() {
    cin >> n;
    for (int i=0; i<2*n; i++) scanf("%lld", &a[i]);
    sort(a, a+2*n, greater<long long>());

    int pos = true;
    for (int i=0; i<2*n; i+=2) {
        pos &= (a[i] == a[i+1]);
    }

    vector<long long> arr(n);
    map<long long, int> seen;

    long long multiplier = 2*n;
    long long subtract = 0;
    for (int i=0; i<n; i++) { // recovering 1th->nth
        a[i*2] -= subtract;
        if (a[i*2] % multiplier != 0) {
            pos = false;
        } else {
            arr[i] = a[i*2]/multiplier;
            pos &= (arr[i] > 0);
            pos &= (seen[arr[i]] == 0);

            seen[arr[i]] = 1;

            subtract += arr[i]*2;
            multiplier -= 2;
        }
    }
    // if (pos) {
    //     for (long long x : arr) {
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
    printf((pos ? "YES\n" : "NO\n"));
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}