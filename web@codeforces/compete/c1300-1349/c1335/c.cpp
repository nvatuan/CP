#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

string  NextString()    { string x; cin >> x; return x; }
int     NextInt()       { int x;    cin >> x; return x; }
llong   NextLong()      { llong x;  cin >> x; return x; }
char    NextChar()      { char x;   cin >> x; return x; }

// --
int n;

void solve() {
    n = NextInt();
    map<int, int> skillCount;
    //
    for (int i = 0; i < n; i++) {
        int a = NextInt();
        skillCount[a]++;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    // --
    auto check = [=](int x) -> bool {
        int difCount = 0;
        int largestSkill = -1;
        int largestSkillCount = -1;
        for ( pair<int, int> p : skillCount ) {
            if (p.second > largestSkillCount) {
                largestSkill = p.first;
                largestSkillCount = p.second;
            }
        }
        if (largestSkillCount > x)  difCount = skillCount.size();
        if (largestSkillCount == x) difCount = skillCount.size() - 1;
        if (largestSkillCount < x)  difCount = -1;
        return (difCount >= x); 
    };
    //
    int L = 1, R = n/2;
    while ( L < R ) {
        int mid = (L + R + 1) / 2;
        if (check(mid)) L = mid;
        else R = mid - 1;
    }
    cout << L << '\n';
}
// --

int main() {
    ios::sync_with_stdio(0);
    //
    for (int t = NextInt(); t; t--) solve();
}