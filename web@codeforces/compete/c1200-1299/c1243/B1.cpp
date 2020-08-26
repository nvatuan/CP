#include <bits/stdc++.h>
using namespace std;

int T, n;
string s, t;

int main(){
    for(cin >> T; T; T--) {
        cin >> n;
        cin >> s >> t;
        // -- sweep for changes
        int dif = 0;
        int idx[2];
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                if(dif < 2) idx[dif] = i;
                dif++;
            }
        }
        // --
        if(dif == 0) {
            cout << "Yes\n";
            continue;
        }
        if(dif != 2) {
            cout << "No\n";
            continue;
        }
        // --
        if(s[idx[0]] == s[idx[1]] and t[idx[0]] == t[idx[1]]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}