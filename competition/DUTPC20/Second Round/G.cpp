#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

const int SIZE = int(1e5)+10;
const llong P = 26;

llong power26[SIZE];
void init() {
    power26[0] = 1;
    for (int i = 1; i < SIZE; i++) power26[i] = power26[i-1] * P;
}

void rollingHash(string look, vector<int>& ap, const string& s) {
    int L = look.length();
    // compute hash for look
    llong hash1 = 0;
    for (int i = 0; i < L; i++) {
        hash1 = hash1 * P + (look[i] - 'a');
    }
    //printf("hash1 = %lld\n", hash1);

    llong hash2 = 0;
    int p1 = 0;
    for (; p1 < L; p1++) {
        hash2 = (hash2 * P + (s[p1] - 'a'));
    }

    int p0 = 0;
    for (; p1 < s.length(); p0++, p1++) {
        //printf("%d| hash2 = %lld\n", p0, hash2);
        if (hash1 == hash2) ap.push_back(p0);
        hash2 = (hash2 - (power26[L-1]*(s[p0] - 'a')));
        hash2 = (hash2 * P + (s[p1] - 'a'));
    }
    //printf("%d| hash2 = %lld\n", p0, hash2);
    if (hash1 == hash2) ap.push_back(p0);
}


int k;
string a, b, s;

vector<int> ap1, ap2;

void solve() {
    ap1.clear(); ap2.clear();
    cin >> k >> s >> a >> b;
    rollingHash(a, ap1, s);
    rollingHash(b, ap2, s);

    //cout << ap1.size() << ' ' << ap2.size() << endl;
    if (ap1.size() == 0 or ap2.size() == 0) {
        cout << "NO\n";
        return;
    }

    int p1 = 0, p2 = 0; 
    while (true) {
        //printf("%d, %d\n", p1, p2);
        if (ap1[p1] <= ap2[p2]) {
            int e1 = ap1[p1] + a.length();
            int e2 = ap2[p2] + b.length();
            //printf("e1 = %d , e2 = %d\n", e1, e2);
            if (e1 > e2) {
                //cout << "YES\n";
                //return;
                p2++;
                if (p2 == ap2.size()) break;
            } else {
                if (ap2[p2] - e1 <= k) {
                    cout << "YES\n";
                    return;
                } else {
                    p1++;
                    if (p1 == ap1.size()) break;
                }
            }
        } else {
            p2++;
            if (p2 == ap2.size()) break;
        }
    }
    cout << "NO\n";
}

int main() {
    init();

    int t; cin >> t;
    while(t--)
        solve();
}