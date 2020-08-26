#include <bits/stdc++.h> 
using namespace std;

int k;
int modulo;
unordered_map<int, int> seen;

void solve() {
    modulo = 0;
    int ans = 0;

    cin >> k;
    do {
        seen[modulo] = 1;
        ans++;
        modulo = modulo*10 + 7;
        modulo %= k;
    } while(seen[modulo] == 0);

    cout << (modulo == 0 ? ans : -1) << '\n';
}

int main() {
    solve();
}