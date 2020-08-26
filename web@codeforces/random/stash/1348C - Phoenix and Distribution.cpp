#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
char maxChar;
string a[1000001];

void solve() {
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    maxChar = s.back();

    fill(a, a + k, "");
    for (int i = 0; i < k; i++) a[i] += s[i];
    
    for (int i = 0, rep = k; rep < n; rep++) {
        if (s[k] < maxChar or a[0][0] < a[k-1][0]) {
            a[0] += s[rep];
        } else {
            a[i] += s[rep];
            i = (i + 1 == k ? 0 : i + 1);
        }
    }

    cout << *max_element(a, a + k) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}
