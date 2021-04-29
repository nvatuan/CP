#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> seq;

int main() {
    cin >> n >> m;

    while (n--) {
        int x; cin >> x;
        seq[x]++;
    }
    while (m--) {
        int x; cin >> x;
        seq[x]++;
    }

    for (auto p : seq) {
        if (p.second == 1) cout << p.first << ' ';
    }
    cout << endl;
}

