#include <bits/stdc++.h>
using namespace std;

int dq(int a, int b, int d) {
    if (d <= 0) return 0;
    int res = a;
    res -= dq(a+1, b+1, d-1);
    res += dq(a-1, b-1, d-1);
    return a+b;
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
    dq(100, -100, 20);
}