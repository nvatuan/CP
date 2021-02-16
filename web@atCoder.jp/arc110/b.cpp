#include <bits/stdc++.h>
using namespace std;

long long l;
int n;
string s;

int repeat() {
    string prefixes[] = {"110", "101", "011"};

    int flag = 0;
    for (int i=0; i<3; i++) {
        string& pr = prefixes[i];
        bool contained = true;
        for (int j=0; j<n; j++) {
            if (s[j] != pr[j%3]) {
                contained = false;
                break;
            }
        }
        if (contained) flag = i+1;
    }
    return flag;
}

int count_string(string tos, string s) {
    int cnt = 0;
    int idx = 0;
    do {
        idx = tos.find(s, idx);
        if (idx != string::npos) cnt++;
        else break;
        idx++;
    } while (true);
    return cnt;
}

long long M = 10000000000LL;

int main() {
    cin >> n >> s;
    if (n < 3) {
        string possible[4] = {"0", "1", "10", "11"};
        if (find(possible, possible+4, s) != possible+4) cout << M << endl;
        else if (s == "01") cout << M - 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    int stat = repeat();
    if (stat)  {
        long long cnt = M - count_string(s, string("110")) + 1;
        if ((s.substr(0, 3) != string("110"))) cnt--;
        if ((s.substr(s.length() - 3, 3) != string("110"))) cnt--;
        cout << cnt << endl;
    } else {
        cout << 0 << endl;
    }

}