#include <bits/stdc++.h>
using namespace std;

vector<char> extractKTuples(string &s, int k) {
    int L = 0;
    int n=s.length();
    map<char, int> cnt;
    vector<int> mark (n, 0);
    vector<char> tupls;

    for (int R = 0; R < n; R++) {
        if (R - L + 1 < k) {
            cnt[s[R]]++;
        } else {
            cnt[s[R]]++;
            if (cnt[s[R]] == k) {
                for (int i=L; i<=R; i++) mark[i] = 1;
                tupls.push_back(s[R]);

                L = R+1;
                cnt.clear();
            } else {
                cnt[s[L]]--;
                L++;
            }
        }
    }
    string rep = "";
    for (int i=0; i<n; i++) if (!mark[i]) rep += s[i];
    s = rep;
    return tupls;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<char> btups = extractKTuples(b, k);

    vector<int> mark(n,0);
    for (int L=0,i=0; i<(int)(b.length()); i++) {
        if (L == n) { printf("No\n"); return; }
        while (a[L] != b[i]) { 
            L++;
            if (L == n) { printf("No\n"); return; }
        }
        mark[L] = 1;
        L++;
    }

    string rep = "";
    for (int i=0; i<n; i++) if (!mark[i]) rep += a[i];
    a = rep;

    vector<char> atups = extractKTuples(a, k);
    if (a != "") { printf("No\n"); return; }
    else {
        if (atups.size() != btups.size()) { printf("No\n"); return; }
        else {
            bool flag = true;
            for (int i = 0; i < (int)(atups.size()); i++) {
                flag &= (atups[i] <= btups[i]);
            }
            if (flag) printf("Yes\n");
            else printf("No\n");
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}