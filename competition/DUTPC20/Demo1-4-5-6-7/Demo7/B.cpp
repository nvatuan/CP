#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[101];
int nim[int(5e5)];

int main() {
    nim[0] = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    sort(a, a + k);

    for (int state = 0; state < n; state++)
        if (!nim[state])
            for (int i = 0; i < k; i++) nim[state + a[i]] = 1;
    cout << (nim[n] ? "Tuan\n" : "Hao\n");
}