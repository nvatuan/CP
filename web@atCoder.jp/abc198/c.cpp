#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll R, X, Y;

int main() {
    cin >> R >> X >> Y;
    double d = sqrt(X*X + Y*Y);

    if (d < R) {
        cout << 2 << endl;
        return 0;
    }

    ll mul = (d / R);
    double margin = d - (mul * R);

    if (margin >= (1e-9)) {
        mul++;
    }
    cout << mul << endl;
}
