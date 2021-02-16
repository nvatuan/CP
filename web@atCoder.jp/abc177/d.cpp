#include <bits/stdc++.h>
using namespace std;

const int N = int(1e6) + 5;
int _size[N], root[N];
int n;

void Init() {
    for (int i=1; i<=n; i++) {
        _size[i] = 1;
        root[i] = i;
    }
}

int GetRoot(int x) {
    while (root[x] != x) {
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}

int Union(int a, int b) {
    int ra = GetRoot(a), rb = GetRoot(b);
    if (ra == rb) return 0;
    else {
        if (_size[ra] < _size[rb]) {
            root[ra] = root[rb];
            _size[rb] += _size[ra];
        } else {
            root[rb] = root[ra];
            _size[ra] += _size[rb];
        }
        return 1;
    }
}


void solve() {
    cin >> n;
    Init();
    int m;
    cin >> m;
    for (int a,b; m; m--) {
        cin >> a >> b;
        Union(a, b);
    }
    cout << *max_element(_size+1, _size + n+1) << '\n';
}

int main() {
    solve();
}