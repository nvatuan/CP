#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    int secmax = 0;

    printf("? %d %d", 1, n); cout << endl;
    cin >> secmax;
    
    if (n == 2) {
        if (secmax == 1) cout << "! " << 2 << endl;
        else cout << "! " << 1 << endl;
        return;
    }

    int move, hold;
    if (secmax == 1 || secmax == n) {
        if (secmax == 1) {
            hold = 1; move = n;
        }
        else {
            hold = n; move = 1;
        }
    } else {
        printf("? %d %d", secmax, n); cout << endl;
        int newsecmax; cin >> newsecmax;
        if (newsecmax == secmax) {
            hold = secmax; move = n;
        } else {
            hold = secmax; move = 1;
        }
    }

    int l = 0, r = abs(hold - move) - 1;
    while (l < r) {
        int mid = (l + r + 1)/2;
        int newmove = (
            move < hold ? move + mid : move - mid
        );

        printf("? %d %d", min(newmove, hold), max(newmove, hold));
        cout << endl;

        int newsecmax; cin >> newsecmax;

        if (newsecmax == secmax) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << "! " << (move < hold ? move + l : move - l) << endl;
}

int main() {
    solve();
}