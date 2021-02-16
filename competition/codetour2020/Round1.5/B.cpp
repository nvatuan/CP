#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    for (cin >> t; t; t--) {
        long long n;
        cin >> n;
        if (n < 4) cout << 0;
        else {
            long long nn = n-2;
            long long last = nn/2;
            if (nn % 2 == 1) cout << last*(last+1);
            else cout << last * (last + 1) - last;
        }
        cout << endl;
    }
}