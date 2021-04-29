#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s1, s2, s3;

void fail() {
    cout << "UNSOLVABLE\n";
    exit(0);
}

int mapping[256];
ll nn[3] = {};

int check(vector<char>& v) {
    for (int i=0; i<v.size(); i++) {
        if (v[i]!='~') mapping[v[i]] = i;
    }

    string ss[3] = {s1, s2, s3};
    fill(nn, nn+3, 0LL);

    for (int i=0; i<3; i++) {
        int isBegin = true;
        for (char c : ss[i]) {
            if (isBegin && mapping[c] == 0) return false;
            isBegin = false;
            nn[i] = nn[i]*10 + (int)(mapping[c]);
        }
    }
    return nn[0] + nn[1] == nn[2];
}

void found() {
    for (int i=0; i<3; i++) {
        cout << nn[i] << endl;
    }
    exit(0);
}

int main() {
    cin >> s1 >> s2 >> s3;
    set<char> uniq;
    for (char c : s1+s2+s3) {
        uniq.insert(c);
    }

    if (uniq.size() > 10) fail();
    vector<char> v;
    for (char c : uniq) v.push_back(c);
    while (v.size() < 10) v.push_back('~');

    do {
        if (check(v)) found();
    } while (next_permutation(v.begin(), v.end()));
    fail();
}
