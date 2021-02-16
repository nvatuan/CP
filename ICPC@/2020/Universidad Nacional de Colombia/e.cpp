#include <bits/stdc++.h>
using namespace std;

int res;
int q = 1;
int n;

void query() {
    cout << q << endl;
    cin >> res;
}

void solve() {
    cin >> n;
    q = 1;
    query();
    if (res == 0) {
        printf("! %d", q);
        cout << endl;
        return;
    }
    //
    q = 3;

    while (true) {
        int prev_res = res;

        query();
        if (res > prev_res) {
            q -= 1;
            res -= 2;
        }
        if (res == 0) {
            printf("! %d", q);
            cout << endl;
            break;
        } else {
            q = q*2 + 1;
        }
    }
}

int main() {
    solve();
}