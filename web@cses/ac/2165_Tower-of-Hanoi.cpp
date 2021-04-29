#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> peg[3];

vector<pair<int, int>> moves;

void recur(int topMost, int from, int to) {
    if (topMost > 1) {
        int middle = 1+2 - from-to;
        recur(topMost-1, from, middle);
        moves.push_back({from, to});
        recur(topMost-1, middle, to);
    } else {
        moves.push_back({from, to});
    }
}

int main() {
    cin >> n;
    for (int i=n; i>0; i--) peg[0].push_back(n);

    recur(n, 0, 2);
    cout << moves.size() << '\n';
    for (auto p : moves) {
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}