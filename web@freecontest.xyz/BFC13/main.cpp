#include <bits/stdc++.h>
using namespace std;

string s;
int l, r;

int main() {
    cin >> s;
    long long ans = 0;
    
    for(int i = 0; i < int(s.length()); i++) {
        vector<int> mark(256, 0);
        for(int j = i+1; j < int(s.length()); j++) {
            if(s[j] == s[i]) break;
            if(!mark[s[j]]) {
                mark[s[j]] = 1;
                ans++;
            }
        }
    }


    cout << ans;
}