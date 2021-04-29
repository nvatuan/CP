#include <bits/stdc++.h>
using namespace std;

int x, y, z;

int main() {
    cin >> x >> y >> z;
    int ans=0;
    for (int i=0; i < (int)(1e6)+10; i++) {
        if (z*y > x*i) ans = max(ans, i);
    }
    cout << ans << endl;
}

