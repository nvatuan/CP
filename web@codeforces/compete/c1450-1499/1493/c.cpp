#include <bits/stdc++.h>
using namespace std;

vector<char> alphabet;

int n, k;
string s;
int cnt[256];

void solve() {
    fill(cnt, cnt+256, 0);
    for (char c : s) cnt[c]++;
    
    int good = 1;
    for (char c : s) {
        good &= !(cnt[c] % k);
    }
    if (good) {
        cout << s << endl;
        return;
    }
    
    for (int i=n-1; i>=0; i--) {
        // printf("i=%d\n", i);
        cnt[s[i]]--;
        
        int msum=0;
        for (char c : alphabet) {
            // printf("%c:%d\t", c, cnt[c]);
            msum += ((k - (cnt[c]%k)) % k);
            // printf("msum=%d\n", msum);
        }
        // printf("msum=%d\n", msum);
        
        for (char nxtchr : alphabet) {
            if (nxtchr > s[i]) {
                msum -= ((k - (cnt[nxtchr]%k)) % k);
                cnt[nxtchr]++;
                msum += ((k - (cnt[nxtchr]%k)) % k);
                
                if (n-i-1 >= msum) {
                    for (int i1=0; i1<i; i1++) cout << s[i1];
                    cout << nxtchr;
                    string postfix;
                    for (char c : alphabet) {
                        while (cnt[c] % k != 0) {
                            postfix += c;
                            cnt[c]++;
                        }
                    }
                    assert(postfix.length() <= (n-i-1));
                    while (postfix.length() < (n-i-1)) postfix += 'a';
                    sort(postfix.begin(), postfix.end());
                    cout << postfix << endl;
                    return;
                }
                
                msum -= ((k - (cnt[nxtchr]%k)) % k);
                cnt[nxtchr]--;
                msum += ((k - (cnt[nxtchr]%k)) % k);
            }
        }
    }
    
    assert ("Failed");
}

int main() {
    for (char c='a'; c<='z'; c++) alphabet.push_back(c);
    
    int t;
    for (cin >> t; t; t--) {
        cin >> n >> k;
        cin >> s;
        if (n % k) cout << -1 << endl;
        else solve();
    }
}