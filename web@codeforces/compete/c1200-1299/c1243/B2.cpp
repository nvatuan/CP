#include <bits/stdc++.h>
using namespace std;

int T, n;
string s, t;

int main(){
    for(cin >> T; T; T--) {
        cin >> n;
        cin >> s >> t;
        // -- checking
        vector<int> cc (26, 0);
        for(char&c : s) cc[int(c-'a')]++;
        for(char&c : t) cc[int(c-'a')]++;
        for(int &i : cc) i /= 2;
        int checksum = 0;
        for(int &i : cc) checksum += i;


        if(checksum != n) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            // --
            int opCount = 0;
            vector< pair<int, int> > op;
            for(int i = 0; i < n; i++) { // t[i] must be equal to s[i]
                if(t[i] != s[i]) {
                    int foundFlag = 0;  // check if there is an occurence in s[i+1]..s[n-1] that can be swap to match s[i] 
                    for(int j = i+1; j < n; j++) {
                        if(s[i] == s[j]) foundFlag = 1;
                    }
                    // --
                    if(!foundFlag) {     // if not found, swap on-sight
                        for(int j = i+1; j < n; j++) {
                            if(t[j] == s[i]) {
                                opCount++;
                                op.push_back({j, j});
                                swap(s[j], t[j]);
                                break;
                            }
                        }
                    }
                    // -- there should exists s[i]
                    for(int j = i+1; j < n; j++) {
                        if(s[i] == s[j]) {
                            opCount++;
                            op.push_back({j, i});
                            swap(t[i], s[j]);
                            break;
                        }
                    }
                }
            }
            // -- done
            cout << opCount << "\n";
            for(pair<int, int> &p : op) {
                cout << p.first+1 << " " << p.second+1 << "\n";
            }
        }
    }
    return 0;
}