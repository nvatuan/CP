#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void solve() {
    cin >>n;
    a.resize(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());

    int globalG = a[0];
    for (int i=1; i<n; i++) {
        int maxG = 0, maxI = 0;
        for (int j=i; j<n; j++) {
            if (maxG < __gcd(globalG, a[j])) {
                maxG = __gcd(globalG, a[j]);
                maxI = j;
            }
        }
        swap(a[i], a[maxI]);
        globalG = __gcd(globalG, a[i]);
    }
    for (int i : a) cout << i <<' ';
    cout <<'\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}