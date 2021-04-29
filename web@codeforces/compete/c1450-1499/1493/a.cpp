#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    vector<int> nums;
    for (int i=k+1; i<=n; i++) nums.push_back(i);

    for (int i=max(1, (k+1)/2); i<k; i++) nums.push_back(i);

    cout << nums.size() << endl;
    for (int i : nums) cout << i << ' ';
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}