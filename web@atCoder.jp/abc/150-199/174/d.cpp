#include <bits/stdc++.h> 
using namespace std;

int n;
string s;
int ans;

void solve() {
    cin >> n;
    cin >> s;
    ans = 0;
    for (int p1 = 0, p2 = n - 1; p1 < p2;) {
        if (s[p1] == 'R') p1++;
        else
        if (s[p2] == 'W') p2--;
        else {
            p1++; p2--;
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}