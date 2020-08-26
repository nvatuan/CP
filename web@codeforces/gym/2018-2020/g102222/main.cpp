#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    string t1, c1, c2;
    cin >> n >> m >> t1 >> c1 >> c2;
    // --
    int dif = (c1[0] - t1[0]);
    for(char &c : c2) {
        printf("%c", ((c - 'A') - dif + 26) % 26 + 'A');
    }
    //
    printf("\n");
}

int main() {
    int T, i = 1;
    for(cin >> T; T; T--, i++) {
        printf("Case #%d: ", i);
        solve();
    }
}