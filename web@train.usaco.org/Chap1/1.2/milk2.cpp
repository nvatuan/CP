/*
ID: nvatuan2
TASK: milk2 
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

int arr[(int)(2e6)];

struct Seg {
    int start, finish;
    Seg() {}
    bool operator<(Seg& s) {
        if (start == s.start) {
            return finish > s.finish;
        }
        return start < s.start;
    }

    bool contain(int moment) {
        return (start <= moment && moment <= finish);
    }
};

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int n;
    cin >> n;

    vector<Seg> s (n);
    for (int i=0; i<n; i++) {
        cin >> s[i].start >> s[i].finish;
    }
    sort(s.begin(), s.end());

    int longMilkingTime = 0;
    int longNonMilkingTime = 0;
    int lastMoment = -1;

    int cumMilkingTime = 0;

    for (int i=0; i<n; i++) {
        if (not s[i].contain(lastMoment)) {
            if (s[i].finish < lastMoment) continue;

            if (lastMoment != -1) {
                longNonMilkingTime = max(longNonMilkingTime, s[i].start - lastMoment);
                longMilkingTime = max(longMilkingTime, cumMilkingTime);
                cumMilkingTime = 0;
            }
            lastMoment = s[i].finish;
            cumMilkingTime = s[i].finish - s[i].start;
        } else {
            cumMilkingTime += (s[i].finish - lastMoment);
            lastMoment = s[i].finish;
        }
    }
    longMilkingTime = max(longMilkingTime, cumMilkingTime);
    cout << longMilkingTime << ' ' << longNonMilkingTime << endl;
}