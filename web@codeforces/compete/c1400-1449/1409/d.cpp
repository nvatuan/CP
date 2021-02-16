#include <bits/stdc++.h>
using namespace std;

unsigned long long n;
int s;

int len;
int ndigit[20];

void cal(unsigned long long x) {
    len = 0;
    while (x > 0) {
        ndigit[len] = x % 10;
        len += 1;
        x /= 10;
    }
    reverse(ndigit, ndigit + len);
}

int digit[20];

unsigned long long dfs(int d, int sd, unsigned long long ncon, unsigned long long n) {
    if (d < len) {
        if (sd >= 0 and ncon >= n) {
            for (int nextd = 0; nextd <= 9; nextd++) {
                unsigned long long res = dfs(d + 1, sd - nextd, ncon*10+nextd, n*10+ndigit[d]);
                if (res > 0) return res;
            }
        } else return 0;
    } else {
        if (sd >= 0 and ncon >= n) return ncon;
        else return 0;
    }
}

void solve() {
    cin >> n >> s;
    cal(n);
    unsigned long long ans = 0;
    for (int fd = 1; fd <= 9; fd++) {
        ans = dfs(1, s-fd, fd, ndigit[0]);
        if (ans > 0) {
            cout << ans - n << '\n';
            return;
        }
    }

    len = len;
    ans = 1;
    while (len--) ans = ans * 10;
    cout << ans - n << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}