#include <bits/stdc++.h>
using namespace std;

int wrap(int x, int offset, int mod) {
    return (x + offset) % mod;
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a (n);
    for (int &i : a) scanf("%d", &i);

    // find starting point
    int start=0;
    int longest_start=-1;

    int new_start=0;
    int curr=-1;
    int longest=0;

    for (int i=0; i<2*n; i++) {
        int j = i%n;

        if (curr >= 0) {
            if (curr < a[j]) curr = a[j];
            curr--;
            longest++;
            if (longest > longest_start) {
                longest_start = longest;
                start = new_start;
            }
        } else {
            curr = a[j] - 1;
            longest_start = 0;
            new_start = j;
        }
    }

    // simulate

    int ptr=start;
    int ticket=-99;
    int ans=0;

    for (int step=0; step<n; step++) {
        if (ticket == -99) {
            ans++;
            ticket = a[ptr];
        }
        //
        if (ticket == -1) {
            if (a[ptr] == 0);
            else {
                ticket = a[ptr]-1;
                ans++;
            }
        } else
        if (ticket == 0) {
            if (a[ptr] == 0) {
                ticket = -1;
            } else {
                ticket = a[ptr];
                ticket--;
            }
        } else {
            if (ticket < a[ptr]) ticket = a[ptr];
            ticket--;
        }
        // --
        ptr = (ptr + 1) % n;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    for (cin >> t; t; t--) solve();
}
