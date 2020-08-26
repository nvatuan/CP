#include <bits/stdc++.h>
using namespace std;

int r, x, a, k;
int Ox, Oy;

vector<pair<int, int>> lattice;

void find() {
    for (int x = -r; x <= r; x++)
        for (int y = -r; y <= r; y++) {
            if (x*x + y*y == r*r) lattice.push_back({x, y});
        }
}

int ans;

int dist(int x, int y) {
    return x*x + y*y;
}

int good(vector<pair<int, int>> sq) {
    assert(sq.size() == 4);
    for (const pair<int, int>& p : sq) {
        for (const pair<int, int>& border : lattice) {
            if (dist(p.first - border.first, p.second - border.second) >= k);
            else return false;
        }
    }
    return true;
}

void placeUp(int y) {
    int L = -r, R = r;
    while (dist(L, y) > r) L++;
    while (dist(R, y) > r) R--;

    while (L < R) {
        if ( good({{L, y}, {L + a, y}, {L, y + a}, {L + a, y + a}}) ) {
            ans++;
            L += (a + k);
        } else L++;
    }
    if (y + a + k <= r) placeUp(y + a + k);
}

void placeDown(int y) {
    int L = -r, R = r;
    while (dist(L, y) > r) L++;
    while (dist(R, y) > r) R--;

    while (L < R) {
        if ( good({{L, y}, {L - a, y}, {L, y - a}, {L - a, y - a}}) ) {
            ans++;
            L += (a + k);
        } else L++;
    }
    if (y - a - k >= -r) placeUp(y - a - k);
}

void solve() {
    lattice.clear();
    ans = 0;
    cin >> r >> x >> a >> k;
    find();

    placeUp(0 + k);
    placeDown(0 - k);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}