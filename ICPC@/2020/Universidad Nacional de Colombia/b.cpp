#include <bits/stdc++.h>
using namespace std;

string a, b;

string lexiMaximumSubstring(string S) {
    int n = (int)(S.length());
    char maxc = S[0];
    int maxpos = 0;

    for (int i=0; i<n; i++) {
        if (maxc < S[i]) {
            maxc = S[i];
            maxpos = i;
            continue;
        } 
        if (S[i] == maxc) {
            for (int j=0; i+j < n; j++) {
                if (maxpos+j == i) {
                    break;
                }
                if (S[maxpos+j] == S[i+j]) continue;
                else {
                    if (S[i+j] > S[maxpos+j]) maxpos = i;
                    i = i+j;
                    break;
                }
            }
        }
    }
    return S.substr(maxpos);
}

int main() {
    cin >> a >> b;
    string la = lexiMaximumSubstring(a);
    string lb = lexiMaximumSubstring(b);

    for (int i=0; i<(int)(la.length()); i++) {
        if (i==0) cout << la[i];
        else if (la[i] >= lb[0]) cout << la[i];
        else break;
    }
    for (char c : lb) cout << c;
    cout << endl;
}
