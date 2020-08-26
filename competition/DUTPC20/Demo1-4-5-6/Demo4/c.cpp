#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int chooseLeft(int l, int r) {
    if (l >= r) return 1;
    if (s[l] == s[r]) {
        return chooseLeft(l+1, r-1);
    } else return s[l] < s[r];
}

int main() {
    cin >> n;
    cin >> s;

    string ans = "";
    int p1 = 0;
    int p2 = n-1;
    while (p1 <= p2) {
        if (chooseLeft(p1, p2)) {
            ans += s[p1];
            p1++;
        } else {
            ans += s[p2];
            p2--;
        }
    }

    cout << ans << endl;
}