#include <bits/stdc++.h>
using namespace std;

int n;
long long R[1000000];
long long B[1000000];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> R[i];
    sort(B, B+n);
    sort(R, R+n);
    // --
    int Bi = 0, Ri = 0;
    long long ans = LLONG_MAX;
    while(Bi < n) {
        while(R[Ri] < B[Bi] && Ri < n) {
            ans = min(ans, abs(R[Ri] - B[Bi]));
            Ri++;
        }
        ans = min(ans, abs(R[Ri] - B[Bi]));
        Bi++;
    }
    // --
    cout << ans;
}
