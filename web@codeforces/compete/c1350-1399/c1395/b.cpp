#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[101][101];

int posX, posY;
void moveNext() {
    v[posX][posY] = 1;
    
    if (v[posX][(posY + 1) % m]) posX = (posX + 1) % n;
    else posY = (posY + 1) % m;
}

void solve() {
    cin >> n >> m >> posX >> posY;
    posX--; posY--;
    for (int i = 0; i < n*m; i++) {
        printf("%d %d\n", posX + 1, posY + 1);
        moveNext();
    }
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}