#include <bits/stdc++.h>
using namespace std;

int a[3], d;

int main() {
    for (int i=0; i<3; i++) cin >> a[i]; cin >> d;

    int ans[3];
    for (int i=0; i<3; i++) {
        int min_id = 0;
        for (int j=0; j<3; j++) if (a[min_id] > a[j]) min_id = j;
        int mn = min(d, a[min_id]);
        d -= mn;
        ans[min_id] = mn;
        a[min_id] = INT_MAX;
    }
    for (int i : ans) cout << i << ' ';
    cout << endl;
}