#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> mapper {
    {'A', -1}, {'B', 1}
};

void solve() {
    int n; cin >> n;
    char c;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c; sum += mapper[c];
    }
    printf(abs(sum) == 1 ? "Y\n" : "N\n");
}

int main() {
    int t; cin >> t;
    for (int it = 1; it <= t; it++) {
        printf("Case #%d: ", it);
        solve();
    }
}