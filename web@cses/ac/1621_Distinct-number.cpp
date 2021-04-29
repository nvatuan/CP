#include<bits/stdc++.h>
using namespace std;

map<int, int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x; s[x]++;
    }
    cout << s.size() << endl;
}
