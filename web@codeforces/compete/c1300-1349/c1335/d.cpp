#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

string  NextString()    { string x; cin >> x; return x; }
int     NextInt()       { int x;    cin >> x; return x; }
llong   NextLong()      { llong x;  cin >> x; return x; }
char    NextChar()      { char x;   cin >> x; return x; }

// --
int n;
char sodoku[9][9];
int coluniq[9], rowuniq[9];

void solve() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            sodoku[i][j] = NextChar();
    fill(coluniq, coluniq + 9, 9);
    fill(rowuniq, rowuniq + 9, 9);
    //
    char from   = char((rand() % 9) + 1 + '0');
    char chosen;
    do {
        chosen = char((rand() % 9) + 1 + '0');
    } while (chosen == from);

    int blockX = 0, blockY = 0;
    for (int num = 0; num < 9; num++) {
        for (int x = 0; x < 3; x++) { 
            for (int y = 0; y < 3; y++) {
//              if ( (coluniq[blockX*3 + x] == 9) and (rowuniq[blockY*3 + y] == 9) 
//                  and (sodoku[blockX * 3 + x][blockY * 3 + y] != chosen) ) {
//                      sodoku[blockX * 3 + x][blockY * 3 + y] = chosen;
//                      coluniq[blockX*3 + x]--;
//                      rowuniq[blockY*3 + y]--;
//                      sel = true;
//                  }
//              if (sel) break;
                if (sodoku[blockX*3 + x][blockY*3 + y] == from) { 
                    sodoku[blockX*3 + x][blockY*3 + y] = chosen; 
                    coluniq[blockX*3 + x]--;
                    rowuniq[blockY*3 + y]--;
                }
            }
//          if (sel) break;
        }
        // --
        blockY++;
        if (blockY == 3) { blockX++; blockY = 0; }
    }
//  for (int i = 0; i < 9; i++) cout << coluniq[i]; 
//  //assert(coluniq[i] == 8);
//  cout << endl;
//  for (int i = 0; i < 9; i++) cout << rowuniq[i];
//  //assert(rowuniq[i] == 8);
//  cout << endl;
    //
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << sodoku[i][j];
        cout << '\n';
    }
}
// --

int main() {
    ios::sync_with_stdio(0);
    //
    for (int t = NextInt(); t; t--) solve();
}