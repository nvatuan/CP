#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i =0; i<n; i++) cin >> a[i];
    int ones = count(a.begin(), a.end(), 1);

    if (ones > n/2) {
        int amount = (n % 4 == 0 ? n/2 : (n/2+1));
        cout << amount << '\n';
        for (int i=0; i<amount; i++) cout << "1 "; cout << endl;
    } else {
        cout << n/2 <<'\n';
        for (int i=0; i<n/2; i++) cout<<"0 "; cout << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}