#include <bits/stdc++.h>
using namespace std;

int grundy[101][101];
int known[101][101];

int main() {
    for(int i = 0; i <= 100; i++) {
        grundy[i][0] = grundy[0][i] = grundy[i][i] = 1;
        known[i][0] = known[0][i] = known[i][i] = 1;
    }
    // ------------------------------------------------
    for(int x = 1; x < 101; x++) {
        for(int y = 1; y < 101; y++) {
            if(!known[x][y]) {
                bool win = 0;
                //
                for(int u = x; u > 0; u--) {
                    win |= !(grundy[x-u][y]);
                }
                for(int u = y; u > 0; u--) {
                    win |= !(grundy[x][y-u]);
                }
                for(int u = min(x, y); u > 0; u--) {
                    win |= !(grundy[x-u][y-u]);
                }
                //
                grundy[x][y] = win;
            }
        }
    }
    // --
    // for(int x = 0; x < 101; x++) {
    //     for(int y = 0; y < 101; y++) {
    //         cout << grundy[x][y];
    //     }
    //     cout << endl;
    // }
    // ------------------------------------------------
    int N;
    int lose_count = 0;
    cin >> N;
    for(int a, b; N; N--) {
        cin >> a >> b;
        if(known[a][b]) {
            cout << "Y";
            return 0;
        }
        lose_count += grundy[a][b];
    }
    cout << ((lose_count) % 2 ? "N" : "Y");
}