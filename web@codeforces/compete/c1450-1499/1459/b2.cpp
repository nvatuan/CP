#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;

    int turn = -1;
    int negdel = 0;
    int posdel = 8;
    int neginc = 3;
    int posinc = 7;

    long long ans = 4;
    while (true) {
        if (n == 1) {
            cout << ans << '\n';
            return;
        }
        n --;

        if (turn > 0) {
            ans += posdel;
            posdel += posinc;
            posinc += 2;
        } else {
            ans -= negdel;
            negdel += neginc;
            neginc += 2;
        }
        turn *= -1;
    }
}

int main() {
    solve();
}