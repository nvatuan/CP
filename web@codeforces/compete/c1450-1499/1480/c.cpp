#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n <= 100) {
        int one_idx = 0;
        int v;
        for (int i=1; i<=n; i++) {
            cout << "? " << i << endl;
            cin >> v;
            if (v == 1) {
                one_idx = i;
                break;
            }
        }
        cout << "! " << one_idx << endl;
    } else {
        map<int, int> known;
        known[0] = known[n+1] = (int)(2e9);

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            for (int i=-1; i<2; i++) {
                if (mid + i > 0 and mid + i <= n)
                    if (known[mid+i] == 0) {
                        cout << "? " << mid + i << endl;
                        cin >> known[mid + i];
                    }
            }
            if (known[mid-1] > known[mid] and known[mid] < known[mid+1]) {
                cout << "! " << mid << endl;
                return;
            } else 
            if (known[mid-1] > known[mid] and known[mid] > known[mid+1]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << "! " << l << endl; // fixed here
    }
}

void solve2() {
    int n; cin >> n;
    map<int, int> v;
    int l = 1, r = n;

    while (l < r) {
        int mid = (l + r) / 2;
        for (int i=0; i<2; i++) {
            if (v[mid+i] == 0) {
                cout << "? " << mid+i << endl;
                cin >> v[mid+i];
            }
        }

        if (v[mid] > v[mid+1]) l = mid+1;
        else r = mid;
    }
    cout << "! " << l << endl;
}

int main() {
    solve();
}