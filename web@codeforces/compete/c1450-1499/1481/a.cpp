#include <bits/stdc++.h>
using namespace std;

int px, py;
string cmd;

map<char, int> dx {
    {'L', -1}, {'R', +1}
};
map<char, int> dy {
    {'U', +1}, {'D', -1}
};

void solve() {
    cin >> px >> py;
    cin >> cmd;
    int u = count(cmd.begin(), cmd.end(), 'U');
    int d = count(cmd.begin(), cmd.end(), 'D');
    int r = count(cmd.begin(), cmd.end(), 'R');
    int l = count(cmd.begin(), cmd.end(), 'L');
    
    int ox=0, oy=0;
    for (char c : cmd) {
        ox += dx[c];
        oy += dy[c];
    }
    int dx = ox - px;
    int dy = oy - py;
    int pos = 1;
    pos &= (
        (dx == 0) or
        (dx > 0 and r >= dx) or 
        (dx < 0 and l >= abs(dx))
    );
    pos &= (
        (dy == 0) or 
        (dy > 0 and u >= dy) or 
        (dy < 0 and d >= abs(dy))
    );
    cout << (pos ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}