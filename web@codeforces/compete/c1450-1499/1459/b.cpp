#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
//    cin >> n;

    queue<tuple<int, int, int, char>> Q;
    Q.push(make_tuple(1, 0, 1, 'U'));
    Q.push(make_tuple(1, 0, -1, 'D'));
    Q.push(make_tuple(1, 1, 0, 'R'));
    Q.push(make_tuple(1, -1, 0, 'L'));

    map<pair<int, int>, int> mark;

    long long ans = 0;
    while (! Q.empty()) {
        int step, x, y; char move;
        tie(step, x, y, move) = Q.front();
        Q.pop();

        if (step == n) {
            ans += (! mark[make_pair(x, y)]);
            mark[make_pair(x, y)] = 1;
            continue;
        } else {
            if (move == 'U' or move == 'D') {
                Q.push(make_tuple(step+1, x-1, y, 'L'));
                Q.push(make_tuple(step+1, x+1, y, 'R'));
            } else 
            if (move == 'L' or move == 'R') {
                Q.push(make_tuple(step+1, x, y+1, 'U'));
                Q.push(make_tuple(step+1, x, y-1, 'D'));
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    for (n = 1; n <= 20; n++) {
        cout << n << ' ';
        solve();
    }
}