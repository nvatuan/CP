#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long sum = 1LL*n*(n+1)/2;
    while (n-- > 1) {
        int x; cin >> x;
        sum -= x;
    }
    cout << sum << endl;
}