#include <bits/stdc++.h>
using namespace std;

int n;
long long W;
pair<long long, int> items[232323];
#define w first
#define index second

#define die cout<<-1<<'\n';return;

void solve() {
    cin >> n >> W;
    for (int i=0; i<n; i++) {
        long long x; cin >> x;
        items[i] = {x, i+1};
    }
    sort(items, items+n);

    long long lower = (W+1)/2;
    long long upper = W;

    long long sum=0;
    int idx = 0;
    while (sum < lower && idx < n) {
        sum += items[idx].w;
        idx++;
    }
    if (sum < lower && idx == n) {
        die;
    }

    if (lower <= sum && sum <= upper) {
        cout << idx << '\n';
        for (int i=0; i<idx; i++) {
            cout << items[i].index << ' ';
        }
        cout << '\n';
        return;
    }

    idx--;
    if (items[idx].w > upper) {
        die;
    } else {
        cout << 1 << '\n';
        cout << items[idx].index << '\n';
        return;
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}