#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    cin >> a >> b;

    int ans=0;
    for (int x=a; x<=b; x++) {
        for (int g=1; 1LL*g*g <= x; g++) {
            if (x % g == 0) {
                int y = b/g * g;
                if (y > x) ans = max(ans, g);

                int g2 = x/g;
                y = b/g2 * g2;
                if (y > x) ans = max(ans, g2);
            }
        }
    }
    cout << ans << endl;
}

