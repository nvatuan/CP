#include <bits/stdc++.h>
using namespace std;

int h, w, k;

int b[6][6];

int total_black = 0;
int black_col[6], black_row[6];

int main() {
    cin >> h >> w >> k;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            b[i][j] = (c == '#' ? 1 : 0);
        }
//    fill(black_col, black_col + 6, 0);
//    fill(black_row, black_row + 6, 0);
//    for (int i = 0; i < h; i++)
//        for (int j = 0; j < w; i++) {
//            black_row[i] += (c[i][j] == '#' ? 1 : 0);
//            black_col[j] += (c[i][j] == '#' ? 1 : 0);
//            total_black += (c[i][j] == '#' ? 1 : 0);
//        }
    //
    int ans = 0;

    int sel_row[6];
    int sel_col[6];
    int blacks;
    
    for (int seth = 0; seth < (1<<h); seth++)
        for (int setw = 0; setw < (1<<w); setw++) {
            blacks = 0;
            fill(sel_row, sel_row + 6, 0);
            fill(sel_col, sel_col + 6, 0);

            for (int r = 0; r < h; r++)
                if (seth & (1 << r))
                    sel_row[r] = 1;
            for (int c = 0; c < w; c++)
                if (setw & (1 << (c)))
                    sel_col[c] = 1;

            for (int r = 0; r < h; r++)
                if (not sel_row[r])
                    for (int c = 0; c < w; c++)
                        if (not sel_col[c]) {
                            blacks += b[r][c];
                        }

            ans += (blacks == k);
        }
    cout << ans << endl;
}